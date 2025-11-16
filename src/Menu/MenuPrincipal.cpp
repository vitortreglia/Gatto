#include "Menu/MenuPrincipal.h"

namespace Menu {
    MenuPrincipal::MenuPrincipal():
    titulo("Gatto", 128, 433, 100),
    Menu()
    {
        fundo.setTextura("Data/Imagens/fundoJardim.jpg"),
        titulo.setFonte("Data/Fontes/RubikBubbles-Regular.ttf");
        criarBotoesMenuPrincipal();
        pGGrafico->setFundo(&fundo);
    }

    MenuPrincipal::~MenuPrincipal() {

    }

    void MenuPrincipal::criarBotoesMenuPrincipal() {
        incluirTexto(&titulo);
        Entidade::Botao* pBotao = new Entidade::Botao("INICIAR");
        pBotao->setPosicao({390, 300});
        incluirBotao(pBotao);
    }
}