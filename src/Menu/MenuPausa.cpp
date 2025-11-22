#include "Menu/MenuPausa.h"

namespace Menu {
    MenuPausa::MenuPausa():
    titulo("Pausa", 128, 433, 100)
    {
        criarBotoesPausa();
    }

    MenuPausa::~MenuPausa() {

    }

    void MenuPausa::criarBotoesPausa() {
        incluirTexto(&titulo);
        Botao* pBotao = new Botao("Continuar");
        pBotao->moverBotao({390, 300});
        incluirBotao(pBotao);
        pBotao = new Botao("Sair");
        pBotao->moverBotao({390, 450});
        incluirBotao(pBotao);
        botoes[selecao]->destacar();
    }

}