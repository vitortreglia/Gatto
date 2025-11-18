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
        }
        pGGrafico->setFundo("Data/Imagens/fundoFaseCidade.png", "", "");
        pGGrafico->setMovimentoFundo(1, 0, 0.5);
        Entidade::Personagem::Inimigo::Gaivota::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        criarCenario("Data/Fases/FaseCidade.dat");
    }

    FaseCidade::~FaseCidade() {

    }

    void FaseCidade::criarProjetil(float x, float y, bool direita) {
        if (direita) {
            x += 80.0f;
        }
        Entidade::Entidade* objEntidade = new Entidade::Itens::Projetil();
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirProjetil(static_cast<Entidade::Itens::Projetil*>(objEntidade));
        }
    }

    void FaseCidade::criarChefao(float x, float y) {
        if ((rand()%10 <= 10 || numInimChefao < 3) && numInimChefao < maxChefoes) {
            Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Rato(x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
                numInimChefao++;
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
            criarPlataforma(x, y);
            criarPlataforma(x + 100, y);
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
            criarPlataforma((*it).second.x, (*it).second.y);
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

}
