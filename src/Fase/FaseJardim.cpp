#include "Fase/FaseJardim.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/GiraGira.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Inimigo/Rato.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    FaseJardim::FaseJardim(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2):
    Fase(1),
    maxInimRato(6),
    maxGiraGira(12),
    numInimRato(0),
    numGiraGira(0)
    {
        pJog1->setPosicao({1700, 5800});
        listaEnt.incluir(pJog1);
        if (pJog2) {
            pJog2->setPosicao({2400, 5800});
            listaEnt.incluir(pJog2);
            numJogs = 2;
            if (pJog1->estaAtivo() && pJog2->estaAtivo())
                pGGrafico->setMultiplayer(true);
            else {
                pGGrafico->setMultiplayer(false);
            }
        }
        pGGrafico->setFundo("Data/Imagens/fundoFaseJardim.png", "Data/Imagens/meioFaseJardim.png", "");
        Entidade::Personagem::Inimigo::Inimigo::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        criarCenario("Data/Fases/FaseJardim.dat");
    }

    FaseJardim::FaseJardim(Entidade::Personagem::Jogador *pJog1, Entidade::Personagem::Jogador *pJog2, istream &carregamento):
    Fase(1),
    maxInimRato(6),
    maxGiraGira(12),
    numInimRato(0),
    numGiraGira(0)
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
        pGGrafico->setFundo("Data/Imagens/fundoFaseJardim.png", "Data/Imagens/meioFaseJardim.png", "");
        Entidade::Personagem::Inimigo::Inimigo::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        buffer.rdbuf(carregamento.rdbuf());
        carregarFase();
    }


    FaseJardim::~FaseJardim() {

    }

    void FaseJardim::criarGiraGira(float x, float y) {
        if ((rand()%10 < 9 || numGiraGira < 3 || y == 0) && numGiraGira < maxGiraGira) {
            Entidade::Entidade* objEntidade = new Entidade::Obstaculo::GiraGira(x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
                numGiraGira++;
            }
        } else {
            criarChao(x, y);
            criarChao(x + 100, y);
        }
    }

    void FaseJardim::criarInimigoRato(float x, float y) {
        if ((rand()%10 < 9 || numInimRato < 3 || y == 0) && numInimRato < maxInimRato) {
            Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Rato(x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
                numInimRato++;
            }
        }
    }

    void FaseJardim::criarInimigos(multimap<char, sf::Vector2f> inimigos) {
        pair<multimap<char, sf::Vector2f>::const_iterator, multimap<char, sf::Vector2f>::const_iterator> grupo =
            inimigos.equal_range('r');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarInimigoRato((*it).second.x, (*it).second.y);
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

    void FaseJardim::criarObstaculos(multimap<char, sf::Vector2f> obstaculos) {
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

        grupo = obstaculos.equal_range('g');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarGiraGira((*it).second.x, (*it).second.y);
        }
    }

    void FaseJardim::carregarFase() {
        string tag;
        Entidade::Personagem::Inimigo::Gaivota* g = nullptr;
        while (!buffer.eof()) {
            buffer >> tag;
            if (tag == "peixe") {
                if (g) {
                    criarPeixe(0, 0, g);
                    g = nullptr;
                } else {
                    criarPeixe(0, 0, nullptr);
                }
            } else if (tag == "rato") {
                criarInimigoRato(0, 0);
            } else if (tag == "gaivota") {
                g = criarInimigoGaivota(0, 0);
            } else if (tag == "chao") {
                criarChao(0, 0);
            } else if (tag == "pmovel") {
                criarPlataformaMovel(0, 0, false);
            } else if (tag == "giragira") {
                criarGiraGira(0, 0);
            } else if (tag == "limites") {
                buffer >> limitesFase.width >> limitesFase.height;
                break;
            }
            listaEnt[listaEnt.getTam()-1]->carregar(buffer);
        }

        pGGrafico->setLimitesCamera(limitesFase);
    }

}
