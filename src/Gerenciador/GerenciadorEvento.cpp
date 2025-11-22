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

    sf::Uint32 GerenciadorEvento::getEntradaTexto() {
        return c;
    }

    sf::Vector2f GerenciadorEvento::getClique() {
        return clique;
    }


    void GerenciadorEvento::verificaTeclasPressionadas(sf::Event evento) {
        if (evento.type == sf::Event::TextEntered) {
            c = evento.text.unicode;
        }

        if (evento.type == sf::Event::KeyPressed) {
            teclasAtivas.insert(evento.key.code);
        }
        if (evento.type == sf::Event::KeyReleased) {
            teclasAtivas.erase(evento.key.code);
            teclasSoltas.insert(evento.key.code);
        }

        if (evento.type == sf::Event::MouseButtonPressed) {
            if (evento.mouseButton.button == sf::Mouse::Left) {
                clique.x = evento.mouseButton.x;
                clique.y = evento.mouseButton.y;
            }
        }
    }

    void GerenciadorEvento::executar() {
        sf::Event evento;
        while (pGGrafico->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                pGGrafico->fecharJanela();
            }
            verificaTeclasPressionadas(evento);
        }
        if (!teclasAtivas.empty() || !teclasSoltas.empty() || (clique.x != 0 && clique.y != 0)) {
            notificar();
            teclasSoltas.clear();
            clique = {0, 0};
            c = 0;
        }
    }



}