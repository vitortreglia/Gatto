 #include "Gerenciador/GerenciadorColisoes.h"

namespace Gerenciador {
    GerenciadorColisoes::GerenciadorColisoes():
    pJogador1(nullptr),
    pJogador2(nullptr)
    {}

    GerenciadorColisoes::~GerenciadorColisoes() {
    }

    void GerenciadorColisoes::incluirObstaculo(Entidade::Obstaculo::Obstaculo *obs) {
        if (obs)
            LOs.push_back(obs);
    }

    void GerenciadorColisoes::incluirJogadores(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2) {
        if (pJog1)
            pJogador1 = pJog1;
        if (pJog2)
            pJogador2 = pJog2;
    }

    void GerenciadorColisoes::incluirInimigo(Entidade::Personagem::Inimigo::Inimigo *pIni) {
        if (pIni)
            LIs.push_back(pIni);
    }

    void GerenciadorColisoes::incluirPeixe(Entidade::Itens::Peixe *pPeixe) {
        if (pPeixe)
            LPxs.push_back(pPeixe);
    }

    void GerenciadorColisoes::incluirProjetil(Entidade::Itens::Projetil *pProjetil) {
        if (pProjetil)
            LPs.insert(pProjetil);
    }

    void GerenciadorColisoes::incluirChao(Entidade::Chao *pChao) {
        if (pChao)
            LCs.push_back(pChao);
    }

    sf::Vector2f GerenciadorColisoes::calculaNormal(const sf::Vector2f& vertice1, const sf::Vector2f& vertice2) {
        // recebe dois vértices e cria um vetor perpendicular
        sf::Vector2f normal;
        float modulo;

        normal.x = - (vertice1.y - vertice2.y); // vetor perpendicular
        normal.y = vertice1.x - vertice2.x;     // vetor perpendicular
        modulo = sqrt(normal.x * normal.x + normal.y * normal.y); // comprimento do vetor
        // divide as normais pelo modulo pra tornar elas unitárias:
        normal.x = normal.x / modulo;
        normal.y = normal.y / modulo;

        return normal; // extrai 4 normais: 2 do corpo 1 e 2 do corpo 2
    }

    vector<pair<float, float>> GerenciadorColisoes::calculaProjecao(const vector<sf::Vector2f> &vertices, const vector<sf::Vector2f> &normal) {
        // para cada eixo normal ele calcula o menor e o maior valor da projeção

        vector<pair<float,float>> projecoes = {{9999999.0f, -9999999.0f}, {9999999.0f, -9999999.0f}, {9999999.0f, -9999999.0f}, {9999999.0f, -9999999.0f}};
        // projecoes guarda um par <min, max> - inicia com valores extremos
        float resultado;

        for (int i = 0; i < 4; i++) {      //loop sobre as normais
            for (int j = 0; j < 4; j++) {  // loop sobre os vértices

                resultado = vertices[j].x * normal[i].x + vertices[j].y * normal[i].y;
                // resultado eh a projeção (produto escalar) de cada vértice na normal

                // atualiza o minimo e o maximo  da projeção para aquela normal:
                if (projecoes[i].first > resultado)
                    projecoes[i].first = resultado;
                if (projecoes[i].second < resultado)
                    projecoes[i].second = resultado;
            }
        }
        return projecoes; // retorna o vetor de projeções
    }

    sf::Vector2f GerenciadorColisoes::calculaSobreposicao(vector<sf::Vector2f> coordCorpo1, vector<sf::Vector2f> coordCorpo2) {
        // para cada normal, calcula quanto cada corpo invadiu o outro

        vector<sf::Vector2f> normais;

        for (int i = 0; i < 2; i++) {
            // pega duas arestas do corpo, calcula suas normais e coloca no vetor de normais criado
            normais.push_back(calculaNormal(coordCorpo1[i], coordCorpo1[i + 1]));
            normais.push_back(calculaNormal(coordCorpo2[i], coordCorpo2[i + 1]));
        }
        // calcula projeção dos dois corpos em todas as normais
        vector<pair<float, float>> projecaoC1 = calculaProjecao(coordCorpo1, normais);
        vector<pair<float, float>> projecaoC2 = calculaProjecao(coordCorpo2, normais);

        float sobreposicao = 999999.0f;
        sf::Vector2f deltaSobreposicao; // vetor de correção da posição

        for (int i = 0; i < 4; i++) {
            //para cada normal calcula duas possiveis sobreposições
            // se algum for menor que a atual, atualiza a sobreposição e atualiza deltaSobreposição na direção da normal

            if (sobreposicao > projecaoC1[i].second - projecaoC2[i].first) {
                sobreposicao = projecaoC1[i].second - projecaoC2[i].first;
                deltaSobreposicao.x = - normais[i].x * sobreposicao;
                deltaSobreposicao.y = - normais[i].y * sobreposicao;
            }
            if (sobreposicao > projecaoC2[i].second - projecaoC1[i].first) {
                sobreposicao = projecaoC2[i].second - projecaoC1[i].first;
                deltaSobreposicao.x = normais[i].x * sobreposicao;
                deltaSobreposicao.y = normais[i].y * sobreposicao;
            }
        }

        if (sobreposicao <= 0.0f) {     // nao houve colisão
            deltaSobreposicao.x = 0.0f;
            deltaSobreposicao.y = 0.0f;
        }

        return deltaSobreposicao; //retorna o vetor de correção
    }


    sf::Vector2f GerenciadorColisoes::verificarColisao(Entidade::Entidade* corpo1, Entidade::Entidade* corpo2) {
        // pega a coordenada dos vértices e passa prara calculaSobreposição(), retornando o vetor de correção

        vector<sf::Vector2f> coordCorpo1 = corpo1->getCoordenadas();
        vector<sf::Vector2f> coordCorpo2 = corpo2->getCoordenadas();

        return calculaSobreposicao(coordCorpo1, coordCorpo2);
    }

    void GerenciadorColisoes::corrigirColisao(Entidade::Personagem::Personagem* pPersonagem, sf::Vector2f colisao) {
        sf::Vector2f deslocamento = pPersonagem->getDeslocamento();
        // recebe um personagem e um vetor de colisão - pega o deslocamento atual do personagem

        if (colisao.y < 0.0f) { // se o personagem esta por cima de algo
            pPersonagem->estaNoChao(true);

            // se estava caindo ou bateu no chão, para a queda
            if (colisao.x != 0.0f) {
                float tg;
                tg = colisao.x / colisao.y;
                if (tg >= -0.6f && tg <= 0.6f && deslocamento.y > 0.0f) {
                    deslocamento.y = 0.0f;
                }
            } else if (deslocamento.y > 0.0f) {
                deslocamento.y = 0.0f;
            }
            if (colisao.y < -30.0f) // colisão muito forte, toma dano
                pPersonagem->tomarDano(100);

        } else if (colisao.y > 0.0f) { // bateu no teto, colisão inverte
            deslocamento.y = deslocamento.y * -1;
        }

        // atualiza a posição do jogador:
        pPersonagem->setDeslocamento(deslocamento);  // pega o vetor de correção
        colisao.x += pPersonagem->getPosicao().x;    // soma a posição
        colisao.y += pPersonagem->getPosicao().y;
        pPersonagem->atualizarPos(colisao);          // move o jogador pra fora da colisão
    }

    void GerenciadorColisoes::tratarColisoesJogsObstacs() {
        sf::Vector2f colisao; // cria um vetor pra guardar sobreposição entre dois corpos

        if (pJogador2) { // se tem outro jogador
            colisao = verificarColisao(pJogador1, pJogador2); //calcula se os dois se sobrepõem
            // cada um desloca metade da correção de colisão e eles se empurram
            if (colisao.x != 0.0f || colisao.y != 0.0f) {
                corrigirColisao(pJogador1, {colisao.x / 2, colisao.y / 2});
                corrigirColisao(pJogador2, {colisao.x * -0.5f, colisao.y * -0.5f});
                if (colisao.y > 0.0f) {
                    pJogador2->pular(0.5f); // se jogador 2 tiver abaixo entao pula - quica um no outro
                } else if (colisao.y < 0.0f) {
                    pJogador1->pular(0.5f);
                }
            }
        }

        for (list<Entidade::Obstaculo::Obstaculo*>::const_iterator it = LOs.begin(); it != LOs.end(); it++) {
            colisao = verificarColisao(pJogador1, *it);
            if (colisao.x != 0.0f || colisao.y != 0.0f) {
                corrigirColisao(pJogador1, colisao); // se houver colisão com o obstaculo, corrige
                if (colisao.y < 0.0f)
                    (*it)->obstaculizar(pJogador1); // se bater no obstaculo por cima, chama obstaculizar()
            }
            // se houver jogador 2, faz o mesmo pra ele
            if (pJogador2) {
                colisao = verificarColisao(pJogador2, *it);
                if (colisao.x != 0.0f || colisao.y != 0.0f) {
                    corrigirColisao(pJogador2, colisao);
                    if (colisao.y < 0.0f)
                        (*it)->obstaculizar(pJogador2);
                }
            }
        }

        for (list<Entidade::Chao*>::const_iterator it = LCs.begin(); it != LCs.end(); it++) {
            // verifica se há colisão com o chão e chama corrigirColisão

            colisao = verificarColisao(pJogador1, *it);
            if (colisao.x != 0.0f || colisao.y != 0.0f) {
                corrigirColisao(pJogador1, colisao);
                if (colisao.y < 0.0f)
                    (*it)->obstaculizar(pJogador1);
            }
            if (pJogador2) {
                colisao = verificarColisao(pJogador2, *it);
                if (colisao.x != 0.0f || colisao.y != 0.0f) {
                    corrigirColisao(pJogador2, colisao);
                    if (colisao.y < 0.0f)
                        (*it)->obstaculizar(pJogador2);
                }
            }
        }
    }

    void GerenciadorColisoes::tratarColisoesJogsInimigs() {
        sf::Vector2f colisao;

            // percorre todos os inimigos da lista:
            for (vector<Entidade::Personagem::Inimigo::Inimigo*>::const_iterator it = LIs.begin(); it != LIs.end(); it++) {
                if ((*it)->estaAtivo()) { // só processa se o inimigo está ativo
                    colisao = verificarColisao(pJogador1, *it);
                    if (colisao.x != 0.0f || colisao.y != 0.0f) { // verifica se tem colisão
                        corrigirColisao(pJogador1, colisao);      // chama corrigirColisao() pra ajustar a posição
                        pJogador1->colidir(*it, colisao);         // chama função colidir
                    }
                    if (pJogador2) {
                        colisao = verificarColisao(pJogador2, *it);
                        if (colisao.x != 0.0f || colisao.y != 0.0f) {
                            corrigirColisao(pJogador2, colisao);
                            pJogador2->colidir(*it, colisao);
                        }
                    }
                }
            }
    }

    void GerenciadorColisoes::tratarColisoesInimigsObstacs() {
        sf::Vector2f colisao;

        // percorre as listas de inimigos e de obstaculo e se houver sobreposição ajusta a posição de inimigo
        for (vector<Entidade::Personagem::Inimigo::Inimigo*>::const_iterator it = LIs.begin(); it != LIs.end(); it++) {
            for (list<Entidade::Obstaculo::Obstaculo*>::const_iterator it2 = LOs.begin(); it2 != LOs.end(); it2++) {
                colisao = verificarColisao(*it, *it2);
                if (colisao.x != 0.0f || colisao.y != 0.0f) {
                    corrigirColisao(*it, colisao);
                }
            }
            for (list<Entidade::Chao*>::const_iterator it2 = LCs.begin(); it2 != LCs.end(); it2++) {
                colisao = verificarColisao(*it, *it2);
                if (colisao.x != 0.0f || colisao.y != 0.0f) {
                    corrigirColisao(*it, colisao);
                }
            }
        }

    }

    void GerenciadorColisoes::tratarColisoesEventos() {
        sf::Vector2f colisao;

        // percorre a lista de peixes e considera os peixes ativos, se tiver peixe, desaativa ele e coleta
        for (vector<Entidade::Itens::Peixe*>::const_iterator it = LPxs.begin(); it != LPxs.end(); it++) {
            if ((*it)->estaAtivo()) {
                colisao = verificarColisao(*it, pJogador1);
                if (colisao.x != 0.0f || colisao.y != 0.0f) {
                    (*it)->setAtivo(false);
                    pJogador1->operator++();
                }
                if (pJogador2) {
                    colisao = verificarColisao(*it, pJogador2);
                    if (colisao.x != 0.0f || colisao.y != 0.0f) {
                        (*it)->setAtivo(false);
                        pJogador2->operator++();
                    }
                }
            }
        }
    }

    void GerenciadorColisoes::tratarColisoesProjeteis() {
        sf::Vector2f colisao;

        // percorre a lista de projeteis, se colidir destiva ele e o jogador leva dano via colidir()
        for (set<Entidade::Itens::Projetil*>::const_iterator it = LPs.begin(); it != LPs.end(); it++) {
            if ((*it)->estaAtivo()) {
                colisao = verificarColisao(pJogador1, *it);
                if (colisao.x != 0.0f || colisao.y != 0.0f) {
                    (*it)->setAtivo(false);
                    pJogador1->colidir(colisao);
                }
                if (pJogador2) {
                    colisao = verificarColisao(pJogador2, *it);
                    if (colisao.x != 0.0f || colisao.y != 0.0f) {
                        (*it)->setAtivo(false);
                        pJogador2->colidir(colisao);
                    }
                }
            }
        }
    }


    void GerenciadorColisoes::executar() {
        tratarColisoesJogsObstacs();
        tratarColisoesJogsInimigs();
        tratarColisoesInimigsObstacs();
        tratarColisoesEventos();
        tratarColisoesProjeteis();
    }


}