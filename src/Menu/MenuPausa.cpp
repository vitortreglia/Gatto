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
        Entidade::Botao* pBotao = new Entidade::Botao("Pausa");
        pBotao->setPosicao({390, 300});
        incluirBotao(pBotao);
    }

}