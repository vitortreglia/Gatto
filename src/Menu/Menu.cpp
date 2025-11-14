#include "Menu/Menu.h"

namespace Menu {
    Menu::Menu(IDs::Ente_IDs id):
    Ente(id, &fundo)
    {
        fundo.setFillColor(sf::Color::White);
        fundo.setSize({1280, 720});
    }

    Menu::~Menu() {

    }

    void Menu::incluirBotao(Entidade::Botao *pB) {
        botoes.push_back(pB);
    }

    void Menu::executar() {
        pGGrafico->desenharUI(&fundo);
        for (std::vector<Entidade::Botao*>::const_iterator it = botoes.begin(); it != botoes.end(); it++) {
            (*it)->executar();
        }
    }


}