#include "Fase/Fase.h"

#include "Entidade/Itens/Peixe.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/Plataforma.h"
#include "Entidade/Obstaculo/PlataformaMovel.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include <time.h>

namespace Fase {
    Fase::Fase(IDs::Ente_IDs id, string caminhoTextura, int nFase):
    Ente(id, &fundo),
    pGColisoes(nullptr),
    limitesFase({0,0,0,0}),
    fundo({1280, 720}),
    numFase(nFase),
    maxInimGaivota(5),
    maxPMovel(15),
    numInimGaivota(0),
    numPMovel(0)
    {
        texturaFundo.setTextura(caminhoTextura);
        pGColisoes = new Gerenciador::GerenciadorColisoes(&listaEnt);
        pGGrafico->setFundo(&texturaFundo);
        pGGrafico->resetaRelogio();
        semearRand();
        //criarFase();
    }

    Fase::~Fase() {
        delete pGColisoes;
    }

    int Fase::semearRand() {
        srand(time(0));
    }

    sf::FloatRect Fase::getLimitesFase() {
        return limitesFase;
    }

    void Fase::criarPlataforma(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::Plataforma(x, y+50);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void Fase::criarPlataformaMovel(float x, float y, bool direcao) {
        if ((rand()%10 < 9 || numPMovel < 3) && numPMovel < maxPMovel) {
            Entidade::Entidade* objEntidade = new Entidade::Obstaculo::PlataformaMovel(x, y+50, direcao);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
                numPMovel++;
            }
        }
    }

    void Fase::criarPeixe(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Itens::Peixe(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirPeixe(static_cast<Entidade::Itens::Peixe*>(objEntidade));
        }
    }

    void Fase::criarInimigoGaivota(float x, float y) {
        if ((rand()%10 < 9 || numInimGaivota < 3) && numInimGaivota < maxInimGaivota) {
            Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Gaivota(x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
                numInimGaivota++;
            }
        }
    }

    void Fase::atualizarEntidades() {
        for (int i = 0; i < listaEnt.getTam(); i++) {
            if (listaEnt[i]->estaAtivo())
                listaEnt[i]->executar();
        }
        pGColisoes->executar();
        for (int i = 0; i < listaEnt.getTam(); i++) {
            if (listaEnt[i]->estaAtivo())
                listaEnt[i]->desenhar();
        }
    }

    int Fase::getFase() {
        return numFase;
    }

    void Fase::executar() {
        Entidade::Entidade::getTempoFrame();
        atualizarEntidades();
    }
}
