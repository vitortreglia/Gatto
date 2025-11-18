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
        Entidade::Botao* pBotao = new Entidade::Botao("Continuar");
        pBotao->setPosicao({390, 300});
        incluirBotao(pBotao);
        pBotao = new Entidade::Botao("Sair");
        pBotao->setPosicao({390, 450});
        incluirBotao(pBotao);
        botoes[selecao]->destacar();
    }

}