#include "Menu/MenuPausa.h"

namespace Menu {
    MenuPausa::MenuPausa():
    titulo("Pausa", 128, 504, 30)
    {
        criarBotoesPausa();
    }

    MenuPausa::~MenuPausa() {

    }

    void MenuPausa::criarBotoesPausa() {
        incluirTexto(&titulo);
        Botao* pBotao = new Botao("Continuar");
        pBotao->moverBotao({440, 240});
        incluirBotao(pBotao);
        pBotao = new Botao("Salvar e Sair");
        pBotao->moverBotao({440, 390});
        incluirBotao(pBotao);
        pBotao = new Botao("Sair");
        pBotao->moverBotao({440, 540});
        incluirBotao(pBotao);
        botoes[selecao]->destacar();
    }

}