#include "Menu/MenuPrincipal.h"

namespace Menu {
    MenuPrincipal::MenuPrincipal():
    titulo("Gatto", 128, 400, 80),
    Menu()
    {
        //fundo.setTextura("Data/Imagens/fundoJardim.jpg"),
        //titulo.setFonte("Data/Fontes/RubikBubbles-Regular.ttf");
        criarBotoesMenuPrincipal();
        //pGGrafico->setFundo(&fundo);
        pGGrafico->setFundo("Data/Imagens/fundoMenu.png", "", "");
    }

    MenuPrincipal::~MenuPrincipal() {

    }

    void MenuPrincipal::criarBotoesMenuPrincipal() {
        //incluirTexto(&titulo);
        Entidade::Botao* pBotao = new Entidade::Botao("UM JOGADOR");
        pBotao->moverBotao({440, 300});
        incluirBotao(pBotao);
        pBotao = new Entidade::Botao("DOIS JOGADORES");
        pBotao->moverBotao({440, 400});
        incluirBotao(pBotao);
        pBotao = new Entidade::Botao("CARREGAR JOGO");
        pBotao->moverBotao({440, 500});
        incluirBotao(pBotao);
        botoes[selecao]->destacar();
    }
}