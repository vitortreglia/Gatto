#include "Fase/FaseJardim.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/GiraGira.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Inimigo/Rato.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    FaseJardim::FaseJardim(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2):
    Fase("Data/Imagens/fundoJardim.jpg", 1),
    maxInimRato(6),
    maxGiraGira(12),
    numInimRato(0),
    numGiraGira(0)
    {
        pJog1->setPosicao({1700, 5800});
        listaEnt.incluir(pJog1);
        if (pJog2) {
            pGGrafico->setMultiplayer(true);
            pJog2->setPosicao({2400, 5800});
            listaEnt.incluir(pJog2);
        }
        Entidade::Personagem::Inimigo::Gaivota::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        criarCenario("Data/Fases/FaseJardim.dat");
        //criarFaseJardim();
    }

    FaseJardim::~FaseJardim() {

    }

    void FaseJardim::criarGiraGira(float x, float y) {
        if ((rand()%10 <= 10 || numGiraGira < 3) && numGiraGira < maxGiraGira) {
            Entidade::Entidade* objEntidade = new Entidade::Obstaculo::GiraGira(x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
                numGiraGira++;
            }
        } else {
            criarPlataforma(x, y);
            criarPlataforma(x + 100, y);
        }
    }

    void FaseJardim::criarInimigoRato(float x, float y) {
        if ((rand()%10 <= 10 || numInimRato < 3) && numInimRato < maxInimRato) {
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
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarInimigoGaivota((*it).second.x, (*it).second.y);
        }
    }

    void FaseJardim::criarObstaculos(multimap<char, sf::Vector2f> obstaculos) {
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

        grupo = obstaculos.equal_range('g');
        for (multimap<char, sf::Vector2f>::const_iterator it = grupo.first; it != grupo.second; it++) {
            criarGiraGira((*it).second.x, (*it).second.y);
        }
    }

}
