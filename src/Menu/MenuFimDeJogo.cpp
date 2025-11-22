#include "Menu/MenuFimDeJogo.h"

namespace Menu {
    MenuFimDeJogo::MenuFimDeJogo(int i):
    titulo("", 72, 400, 80){
        if (i == 2) {
            titulo.setTexto("Jogador 1 Venceu!");
        } else {
            titulo.setTexto("Jogador 1 Venceu!");
        }
        pGGrafico->setFundo("Data/Imagens/fundoFaseJardim.png", "", "");
        pGGrafico->setMovimentoFundo(0, 0, 0);
        CriarMenuFimDeJogo();
    }

    MenuFimDeJogo::~MenuFimDeJogo() {

    }

    void MenuFimDeJogo::CriarMenuFimDeJogo() {
        entrada.setPosicao(440, 300);
        Botao* pBotao = new Botao("VOLTAR AO MENU");
        pBotao->moverBotao({440, 400});
        incluirBotao(pBotao);
    }

    bool MenuFimDeJogo::tratarCliques(sf::Vector2f c) {
        int i = 0;
        sf::FloatRect b;
        b = entrada.getCoordCaixa();
        if (c.x > b.left && c.x < b.width + b.left && c.y > b.top && c.y < b.height + b.top) {
            selecao = i;
            return true;
        }
        i++;
        for (std::vector<Botao*>::const_iterator it = botoes.begin(); it != botoes.end(); it++) {
            b = (*it)->getCoordBotao();
            if (c.x > b.left && c.x < b.width + b.left && c.y > b.top && c.y < b.height + b.top) {
                selecao = i;
                return true;
            }
            i++;
        }
        return false;
    }

    void MenuFimDeJogo::digitar() {
        entrada.setDigitando(true);
        entrada.observarEntrada();
    }

    string MenuFimDeJogo::getNome() {
        return entrada.getEntrada();
    }

    void MenuFimDeJogo::pararDigitar() {
        entrada.setDigitando(false);
    }

    bool MenuFimDeJogo::getDigitando() {
        return entrada.getDigitando();
    }

    void MenuFimDeJogo::executar() {
        titulo.executar();
        entrada.executar();
        Menu::executar();
    }


}