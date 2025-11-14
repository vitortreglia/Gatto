#include "Menu/MenuPausa.h"

namespace Menu {
    MenuPausa::MenuPausa():
    Menu(IDs::Ente_IDs::MenuPausa)
    {
        criarBotoesPausa();
    }

    MenuPausa::~MenuPausa() {

    }

    void MenuPausa::criarBotoesPausa() {
        Botao* pBotao = new Botao("Pausa");
        incluirBotao(pBotao);
    }

}