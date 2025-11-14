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
        Entidade::Botao* pBotao = new Entidade::Botao("PRESSIONE ENTER PARA COMEÇAR");
        incluirBotao(pBotao);
    }
}