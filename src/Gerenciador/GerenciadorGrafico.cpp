#include "Gerenciador/GerenciadorGrafico.h"

namespace Gerenciador {

    GerenciadorGrafico* GerenciadorGrafico::pGGrafico(nullptr);

    GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Gatto"))
    {
        if (window == nullptr) {
            cout << "Nao foi possivel criar a janela grafica" << endl;
            exit(1);
        }
    }

    GerenciadorGrafico::~GerenciadorGrafico() {
        if (window) {
            delete(window);
            window = nullptr;
        }
    }

    GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
        if (!pGGrafico) {
            pGGrafico = new GerenciadorGrafico();
        }
        return pGGrafico;
    }

    sf::RenderWindow* GerenciadorGrafico::getWindow() const {
        return window;
    }

    void GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo) {
        window->draw(corpo);
    }

    void GerenciadorGrafico::mostraElementos() {
        window->display();
    }

    const bool GerenciadorGrafico::verificaJanelaAberta() {
        if (window->isOpen())
            return true;
        return false;
    }

    void GerenciadorGrafico::fecharJanela() {
        window->close();
    }

    void GerenciadorGrafico::limpaJanela() {
        window->clear();
    }

    float GerenciadorGrafico::getTempo() {
        return tempo;
    }

    void GerenciadorGrafico::resetaRelogio() {
        tempo = relogio.getElapsedTime().asSeconds();
        relogio.restart();
    }


}


