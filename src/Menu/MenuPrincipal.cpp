#include "Menu/MenuPrincipal.h"

namespace Menu {
    MenuPrincipal::MenuPrincipal():
    titulo("Gatto", 128, 400, 80),
    Menu()
    {
        criarBotoesMenuPrincipal();
        pGGrafico->setFundo("Data/Imagens/fundoMenu.png", "", "");
        pGGrafico->setMovimentoFundo(0, 0, 0);
    }

    MenuPrincipal::~MenuPrincipal() {

    }

    void MenuPrincipal::criarBotoesMenuPrincipal() {
        Botao* pBotao = new Botao("UM JOGADOR");
        pBotao->moverBotao({440, 300});
        incluirBotao(pBotao);
        pBotao = new Botao("DOIS JOGADORES");
        pBotao->moverBotao({440, 400});
        incluirBotao(pBotao);
        pBotao = new Botao("CARREGAR JOGO");
        pBotao->moverBotao({440, 500});
        incluirBotao(pBotao);
        botoes[selecao]->destacar();
    }
}