#include "Menu/MenuPrincipal.h"

namespace Menu {
    MenuPrincipal::MenuPrincipal():
    Menu(IDs::Ente_IDs::MenuPrincipal)
    {
        criarBotoesMenuPrincipal();
    }

    MenuPrincipal::~MenuPrincipal() {

    }

    void MenuPrincipal::criarBotoesMenuPrincipal() {
        Botao* pBotao = new Botao("PRESSIONE ENTER PARA COMEÇAR");
        incluirBotao(pBotao);
    }
}