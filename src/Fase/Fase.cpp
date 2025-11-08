#include "Fase/Fase.h"

#include "Entidade/Itens/Peixe.h"
#include "Entidade/Itens/Projetil.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/Plataforma.h"
#include "Entidade/Obstaculo/PlataformaGiratoria.h"
#include "Entidade/Obstaculo/PlataformaMovel.h"
#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Inimigo/Rato.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    Fase::Fase():
    pGColisoes(nullptr),
    limitesFase({0,0,0,0})
    {
        pGColisoes = new Gerenciador::GerenciadorColisoes(&listaEnt);
        //criarFase();
    }

    Fase::~Fase() {
        delete pGColisoes;
    }

    sf::FloatRect Fase::getLimitesFase() {
        return limitesFase;
    }


    void Fase::criarPlataforma(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::Plataforma(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void Fase::criarPeixe(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Itens::Peixe(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirPeixe(static_cast<Entidade::Itens::Peixe*>(objEntidade));
        }
    }

    void Fase::criarInimigoRato(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Rato(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
        }
    }


    void Fase::criarProjetil(float x, float y, bool direita) {
        if (direita) {
            x += 80.0f;
        }
        Entidade::Entidade* objEntidade = new Entidade::Itens::Projetil(x, y, direita);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirProjetil(static_cast<Entidade::Itens::Projetil*>(objEntidade));
        }
    }


    void Fase::criarFase() {

    }

    void Fase::atualizarEntidades() {
        for (int i = 0; i < listaEnt.getTam(); i++) {
            if (listaEnt[i]->getId() == IDs::IDs::InimigoRato) {
                if (static_cast<Entidade::Personagem::Inimigo::Rato*>(listaEnt[i])->getAtirou()) {
                    static_cast<Entidade::Personagem::Inimigo::Rato*>(listaEnt[i])->setAtirou(false);
                    criarProjetil(listaEnt[i]->getPosicao().x, listaEnt[i]->getPosicao().y, static_cast<Entidade::Personagem::Inimigo::Rato*>(listaEnt[i])->getDireita());
                }
            }
            if (listaEnt[i]->estaAtivo())
                listaEnt[i]->executar();
        }
        pGColisoes->executar();
        for (int i = 0; i < listaEnt.getTam(); i++) {
            if (listaEnt[i]->getId() == IDs::IDs::InimigoRato) {
                if (static_cast<Entidade::Personagem::Inimigo::Rato*>(listaEnt[i])->getAtirou()) {
                    static_cast<Entidade::Personagem::Inimigo::Rato*>(listaEnt[i])->setAtirou(false);
                    criarProjetil(listaEnt[i]->getPosicao().x, listaEnt[i]->getPosicao().y, static_cast<Entidade::Personagem::Inimigo::Rato*>(listaEnt[i])->getDireita());
                }
            }
            if (listaEnt[i]->estaAtivo())
                listaEnt[i]->desenhar();
        }
    }


    void Fase::executar() {
        Entidade::Entidade::getTempoFrame();
        atualizarEntidades();
    }
}
