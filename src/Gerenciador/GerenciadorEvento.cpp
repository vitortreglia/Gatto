#include "Gerenciador/GerenciadorEvento.h"

namespace Gerenciador {
    GerenciadorEvento* GerenciadorEvento::pGEvento(nullptr);
    Entidade::Personagem::Jogador* GerenciadorEvento::pJogador(nullptr);

    GerenciadorEvento::GerenciadorEvento():
    pGGrafico(GerenciadorGrafico::getGerenciadorGrafico())
    {}

    GerenciadorEvento::~GerenciadorEvento() {
        pGEvento = nullptr;
        pJogador = nullptr;
    }


    GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento() {
        if (!pGEvento) {
            pGEvento = new GerenciadorEvento();
        }
        return pGEvento;
    }

    void GerenciadorEvento::setJogador(Entidade::Personagem::Jogador *pJ) {
        pJogador = pJ;
    }

    void GerenciadorEvento::verificaTeclaPressionada() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            pJogador->andar(false);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            pJogador->andar(true);
        } else {
            pJogador->parar();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            pJogador->pular(1);
        } else {
            pJogador->liberaPulo();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            pJogador->setAtacando(true);
        }
    }

    void GerenciadorEvento::verificaTeclaSolta() {
        /*if (sf::Keyboard::(sf::Keyboard::A)) {
            pJogador->parar();
        } else if (tecla == sf::Keyboard::D) {
            pJogador->parar();
        }*/

    }

    void GerenciadorEvento::executar() {
        sf::Event evento;
        while (pGGrafico->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                pGGrafico->fecharJanela();
            }
        }
        verificaTeclaPressionada();
    }


}