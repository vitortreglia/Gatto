#include "../../includes/Gerenciador/GerenciadorEvento.h"

namespace Gerenciador {
    GerenciadorEvento::GerenciadorEvento():
    pGGrafico(pGGrafico->getGerenciadorGrafico()),
    pJogador(nullptr)
    {}

    GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento() {
        if (!pGEvento) {
            pGEvento = new GerenciadorEvento();
        }
        return pGEvento;
    }

    void GerenciadorEvento::setJogador(Jogador::Jogador *pJ) {
        pJogador = pJ;
    }

    void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            corpo.move(-vel.x, 0.0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            corpo.move(vel.x, 0.0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            corpo.move(0.0, -vel.y);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            corpo.move(0.0, vel.y);
        }
    }

    void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla) {

    }

    void GerenciadorEvento::executar() {
        sf::Event evento;
        while (pGGrafico->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::KeyPressed) {
                verificaTeclaPressionada(evento.key.code);
            } else if (evento.type == sf::Event::KeyReleased) {
                verificaTeclaSolta(evento.key.code);
            } else if (evento.type == sf::Event::Closed) {
                pGGrafico->fecharJanela();
            }
        }
    }


}