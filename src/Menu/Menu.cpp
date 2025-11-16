#include "Menu/Menu.h"

namespace Menu {
    Menu::Menu():
    Ente(&fundo)
    {
        //fundo.setFillColor(sf::Color::White);
        fundo.setSize({1280, 720});
    }

    Menu::~Menu() {

    }

    void Menu::incluirBotao(Entidade::Botao *pB) {
        botoes.push_back(pB);
    }

    void Menu::incluirTexto(Texto *pT) {
        textos.push_back(pT);
    }

    void Menu::executar() {
        for (std::vector<Entidade::Botao*>::const_iterator it = botoes.begin(); it != botoes.end(); it++) {
            (*it)->executar();
        }
        for (std::vector<Texto*>::const_iterator it = textos.begin(); it != textos.end(); it++) {
            (*it)->executar();
        }
    }


}