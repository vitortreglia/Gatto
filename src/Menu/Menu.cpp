#include "Menu/Menu.h"

namespace Menu {
    Menu::Menu():
    Ente(&fundo),
    selecao(0)
    {
        //fundo.setFillColor(sf::Color::White);
        fundo.setSize({1280, 720});
    }

    Menu::~Menu() {

    }

    void Menu::incluirBotao(Botao *pB) {
        botoes.push_back(pB);
    }

    void Menu::incluirTexto(Texto *pT) {
        textos.push_back(pT);
    }

    void Menu::executar() {
        for (std::vector<Botao*>::const_iterator it = botoes.begin(); it != botoes.end(); it++) {
            (*it)->executar();
        }
        for (std::vector<Texto*>::const_iterator it = textos.begin(); it != textos.end(); it++) {
            (*it)->executar();
        }
    }

    void Menu::proximo() {
        botoes[selecao]->tirarDestaque();
        if (selecao < botoes.size() - 1)
            selecao++;
        else
            selecao = 0;
        botoes[selecao]->destacar();
    }

    void Menu::anterior() {
        botoes[selecao]->tirarDestaque();
        if (selecao > 0)
            selecao--;
        else
            selecao = botoes.size() - 1;
        botoes[selecao]->destacar();
    }

    int Menu::getSelecao() {
        return selecao;
    }

    bool Menu::tratarCliques(sf::Vector2f c) {
        int i = 0;
        sf::FloatRect b;
        for (std::vector<Botao*>::const_iterator it = botoes.begin(); it != botoes.end(); it++) {
            b = (*it)->getCoordBotao();
            if (c.x > b.left && c.x < b.width + b.left && c.y > b.top && c.y < b.height + b.top) {
                selecao = i;
                return true;
            }
            i++;
        }
        return false;
    }


}