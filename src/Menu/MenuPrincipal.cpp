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
        Botao* pBotao = new Botao("Um Jogador");
        pBotao->moverBotao({440, 300});
        incluirBotao(pBotao);
        pBotao = new Botao("Dois Jogadores");
        pBotao->moverBotao({440, 400});
        incluirBotao(pBotao);
        pBotao = new Botao("Carregar Jogo");
        pBotao->moverBotao({440, 500});
        incluirBotao(pBotao);
        pBotao = new Botao("Ranking");
        pBotao->moverBotao({440, 600});
        incluirBotao(pBotao);
        botoes[selecao]->destacar();
    }
}