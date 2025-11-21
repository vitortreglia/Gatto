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
            pGGrafico->setMultiplayer(true);
            pJog2->setPosicao({2400, 2700});
            listaEnt.incluir(pJog2);
            numJogs = 2;
        }
        pGGrafico->setFundo("Data/Imagens/fundoFaseCidade.png", "", "");
        pGGrafico->setMovimentoFundo(1, 0, 0.5);
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
        }
        pGGrafico->setFundo("Data/Imagens/fundoFaseCidade.png", "", "");
        pGGrafico->setMovimentoFundo(1, 0, 0.5);
        Entidade::Personagem::Inimigo::Inimigo::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        carregarFase();
    }

    FaseCidade::~FaseCidade() {

    }

    void FaseCidade::criarProjetil(float x, float y, bool direita,
        Entidade::Personagem::Inimigo::Cachorro* pCachorro) {

        if (!pCachorro)
            return;

        sf::Vector2f pos = pCachorro->getPosicao();

        Entidade::Itens::Projetil* proj = new Entidade::Itens::Projetil();

        if (proj) {
            proj->setAtivo(false);
            proj->setDirecao(direita);
            proj->setPosicao(pos);

            listaEnt.incluir(proj);
            pGColisoes->incluirProjetil(proj);

            pCachorro->setProjetil(proj);
        }
    }


    void FaseCidade::criarChefao(float x, float y) {
        if ((rand()%10 < 9 || numInimChefao < 3) && numInimChefao < maxChefoes) {
            auto* cachorro = new Entidade::Personagem::Inimigo::Cachorro(x, y);
            if (cachorro) {
                listaEnt.incluir(cachorro);
                pGColisoes->incluirInimigo(
                    static_cast<Entidade::Personagem::Inimigo::Inimigo*>(cachorro)
                );
                numInimChefao++;
                criarProjetil(x, y, true, cachorro);
            }
        }
    }

    void FaseCidade::criarRoseira(float x, float y, bool danoso) {
        if ((rand()%10 <= 10 || numRoseira < 3) && numRoseira < maxRoseiras) {
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
            criarChefao((*it).second.x, (*it).second.y);
        }

        grupo = inimigos.equal_range('v');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarInimigoGaivota((*it).second.x, (*it).second.y);
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

    }

}
