#include "Gerenciador/GerenciadorEvento.h"

namespace Gerenciador {
    GerenciadorEvento* GerenciadorEvento::pGEvento(nullptr);


    GerenciadorEvento::GerenciadorEvento():
    pGGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
    pJogador(nullptr)
    {}

    GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento() {
        if (!pGEvento) {
            pGEvento = new GerenciadorEvento();
        }
        return pGEvento;
    }

    void GerenciadorEvento::setJogador(Entidade::Personagem::Jogador *pJ) {
        pJogador = pJ;
    }

    void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla) {
        if (tecla == sf::Keyboard::A) {
            pJogador->andar(false);
        } else if (tecla == sf::Keyboard::D) {
            pJogador->andar(true);
        }
    }

    void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla) {
        if (tecla == sf::Keyboard::A) {
            pJogador->parar();
        } else if (tecla == sf::Keyboard::D) {
            pJogador->parar();
        }
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