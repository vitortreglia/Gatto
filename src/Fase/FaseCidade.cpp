#include "Fase/FaseCidade.h"
#include "Entidade/Obstaculo/Roseira.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Inimigo/Rato.h"

namespace Fase {
    FaseCidade::FaseCidade(Entidade::Personagem::Jogador *pJog1, Entidade::Personagem::Jogador *pJog2):
    Fase(2),
    maxChefoes(5),
    maxRoseiras(20),
    numRoseira(0),
    numInimChefao(0)
    {
        pJog1->setPosicao({1100, 2700});
        listaEnt.incluir(pJog1);
        if (pJog2) {
            pJog2->setPosicao({2400, 2700});
            listaEnt.incluir(pJog2);
            numJogs = 2;
            if (pJog1->estaAtivo() && pJog2->estaAtivo())
                pGGrafico->setMultiplayer(true);
            else {
                pGGrafico->setMultiplayer(false);
            }
        }
        pGGrafico->setFundo("Data/Imagens/fundoFaseCidade.png", "", "");
        pGGrafico->setMovimentoFundo(0, 0, 0.5);
        Entidade::Personagem::Inimigo::Inimigo::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        criarCenario("Data/Fases/FaseCidade.dat");
    }

    FaseCidade::FaseCidade(Entidade::Personagem::Jogador *pJog1, Entidade::Personagem::Jogador *pJog2, istream &carregamento):
    Fase(2),
    maxChefoes(5),
    maxRoseiras(20),
    numRoseira(0),
    numInimChefao(0)
    {
        listaEnt.incluir(pJog1);
        if (pJog2) {
            pGGrafico->setMultiplayer(true);
            listaEnt.incluir(pJog2);
            numJogs = 2;
            if (pJog1->estaAtivo() && pJog2->estaAtivo())
                pGGrafico->setMultiplayer(true);
            else {
                pGGrafico->setMultiplayer(false);
            }
        }
        pGGrafico->setFundo("Data/Imagens/fundoFaseCidade.png", "", "");
        pGGrafico->setMovimentoFundo(1, 0, 0.5);
        Entidade::Personagem::Inimigo::Inimigo::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        buffer.rdbuf(carregamento.rdbuf());
        carregarFase();
    }

    FaseCidade::~FaseCidade() {

    }

    void FaseCidade::criarProjetil(float x, float y, bool direita,
        Entidade::Personagem::Inimigo::Cachorro* pCachorro) {


        Entidade::Itens::Projetil* proj = new Entidade::Itens::Projetil();

        if (proj) {
            proj->setAtivo(false);
            proj->setDirecao(direita);

            listaEnt.incluir(proj);
            pGColisoes->incluirProjetil(proj);
            if (pCachorro)
                pCachorro->setProjetil(proj);
        }
    }


    Entidade::Personagem::Inimigo::Cachorro* FaseCidade::criarChefao(float x, float y) {
        if ((rand()%10 < 9 || numInimChefao < 3 || y == 0) && numInimChefao < maxChefoes) {
            Entidade::Personagem::Inimigo::Cachorro* cachorro = new Entidade::Personagem::Inimigo::Cachorro(x, y);
            if (cachorro) {
                listaEnt.incluir(cachorro);
                pGColisoes->incluirInimigo(
                    static_cast<Entidade::Personagem::Inimigo::Inimigo*>(cachorro)
                );
                numInimChefao++;
                return cachorro;
            }
        }
        return nullptr;
    }

    void FaseCidade::criarRoseira(float x, float y, bool danoso) {
        if ((rand()%10 <= 9 || numRoseira < 3 || y == 0) && numRoseira < maxRoseiras) {
            Entidade::Entidade* objEntidade = new Entidade::Obstaculo::Roseira(danoso, x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
                numRoseira++;
            }
        } else {
            criarChao(x, y);
            criarChao(x + 100, y);
        }
    }

    void FaseCidade::criarInimigos(multimap<char, sf::Vector2f> inimigos) {
        pair<multimap<char, sf::Vector2f>::const_iterator, multimap<char, sf::Vector2f>::const_iterator> grupo =
                    inimigos.equal_range('c');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            Entidade::Personagem::Inimigo::Cachorro* c = criarChefao((*it).second.x, (*it).second.y);
            if (c)
                criarProjetil((*it).second.x, (*it).second.y, true ,c);
            c = nullptr;
        }

        grupo = inimigos.equal_range('v');
        Entidade::Personagem::Inimigo::Gaivota* pG = nullptr;
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            pG = criarInimigoGaivota((*it).second.x, (*it).second.y);
            if (pG) {
                criarPeixe(0, 0, pG);
            }
            pG = nullptr;
        }
    }

    void FaseCidade::criarObstaculos(multimap<char, sf::Vector2f> obstaculos) {
        pair<multimap<char, sf::Vector2f>::const_iterator, multimap<char, sf::Vector2f>::const_iterator> grupo =
                    obstaculos.equal_range('p');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarChao((*it).second.x, (*it).second.y);
        }

        grupo = obstaculos.equal_range('m');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarPlataformaMovel((*it).second.x, (*it).second.y, false);
        }

        grupo = obstaculos.equal_range('n');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarPlataformaMovel((*it).second.x, (*it).second.y, true);
        }

        grupo = obstaculos.equal_range('o');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarRoseira((*it).second.x, (*it).second.y, true);
        }

        grupo = obstaculos.equal_range('O');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarRoseira((*it).second.x, (*it).second.y, false);
        }
    }

    void FaseCidade::carregarFase() {
        string tag;
        vector<Entidade::Personagem::Inimigo::Cachorro*> c;
        vector<Entidade::Personagem::Inimigo::Gaivota*> g;
        while (!buffer.eof()) {
            buffer >> tag;
            if (tag == "peixe") {
                criarPeixe(0, 0, nullptr);
            } else if (tag == "cachorro") {
                c.push_back(criarChefao(0, 0));
            } else if (tag == "projetil") {
                criarProjetil(0, 0, true, nullptr);
            } else if (tag == "gaivota") {
                g.push_back(criarInimigoGaivota(0, 0));
            } else if (tag == "chao") {
                criarChao(0, 0);
            } else if (tag == "pmovel") {
                criarPlataformaMovel(0, 0, false);
            } else if (tag == "roseira") {
                criarRoseira(0, 0, false);
            } else if (tag == "limites") {
                buffer >> limitesFase.width >> limitesFase.height;
                break;
            }
            listaEnt[listaEnt.getTam()-1]->carregar(buffer);
        }
        for (vector<Entidade::Personagem::Inimigo::Cachorro*>::const_iterator it = c.begin(); it != c.end(); it++) {
            for (int i = 0; i < listaEnt.getTam(); i++) {
                if (listaEnt[i]->getId() == (*it)->getProjetilID()) {
                    (*it)->setProjetil(static_cast<Entidade::Itens::Projetil*>(listaEnt[i]));
                }
            }
        }
        for (vector<Entidade::Personagem::Inimigo::Gaivota*>::const_iterator it = g.begin(); it != g.end(); it++) {
            for (int i = 0; i < listaEnt.getTam(); i++) {
                if (listaEnt[i]->getId() == (*it)->getPeixeID()) {
                    (*it)->setPeixe(static_cast<Entidade::Itens::Peixe*>(listaEnt[i]));
                }
            }
        }
        pGGrafico->setLimitesCamera(limitesFase);
    }

}
