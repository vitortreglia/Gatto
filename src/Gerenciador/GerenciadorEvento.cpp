#include "Gerenciador/GerenciadorEvento.h"

namespace Gerenciador {
    GerenciadorEvento* GerenciadorEvento::pGEvento(nullptr);

    GerenciadorEvento::GerenciadorEvento():
    pGGrafico(GerenciadorGrafico::getGerenciadorGrafico())
    {}

    GerenciadorEvento::~GerenciadorEvento() {
        pGEvento = nullptr;
        //pJogador = nullptr;
    }

    GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento() {
        if (!pGEvento) {
            pGEvento = new GerenciadorEvento();
        }
        return pGEvento;
    }

    std::set<sf::Keyboard::Key> GerenciadorEvento::getTeclasPressionadas() {
        return teclasAtivas;
    }

    std::set<sf::Keyboard::Key> GerenciadorEvento::getTeclasSoltas() {
        return teclasSoltas;
    }

    void GerenciadorEvento::verificaTeclasPressionadas(sf::Event evento) {
        if (evento.type == sf::Event::KeyPressed) {
            teclasAtivas.insert(evento.key.code);
        }
        if (evento.type == sf::Event::KeyReleased) {
            teclasAtivas.erase(evento.key.code);
            teclasSoltas.insert(evento.key.code);
        }

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //pJogador->andar(false);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            //pJogador->andar(true);
        } else {
            //pJogador->parar();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            //pJogador->pular(1);
        } else {
            //pJogador->liberaPulo();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            //pJogador->atacar();
        } else {
            //pJogador->liberaAtaque();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            pGEstados->sair();
        }*/
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
            verificaTeclasPressionadas(evento);
        }
        if (!teclasAtivas.empty() || !teclasSoltas.empty()) {
            notificar();
            teclasSoltas.clear();
        }
    }



}