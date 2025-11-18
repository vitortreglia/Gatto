#include "Menu/MenuPausa.h"

namespace Menu {
    MenuPausa::MenuPausa()
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