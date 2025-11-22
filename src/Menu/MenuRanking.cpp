#include "Menu/MenuRanking.h"

namespace Menu {
    MenuRanking::MenuRanking(multimap<int, string, std::greater<int>> r):
    ranking(r) {
        criarMenuRanking();
        pGGrafico->setFundo("Data/Imagens/fundoFaseJardim.png", "", "");
        pGGrafico->setMovimentoFundo(0, 0, 0);
    }

    MenuRanking::~MenuRanking() {}

    void MenuRanking::criarMenuRanking() {
        float y = 20;
        string r;
        Texto* rank = new Texto("Ranking", 60, 546, y);
        incluirTexto(rank);
        y += 80;
        for (multimap<int, string>::const_iterator it = ranking.begin(); it != ranking.end(); it++) {
            r = (*it).second + "....." + std::to_string((*it).first);
            rank = new Texto(r, 36, 530, y);
            incluirTexto(rank);
            y += 40;
        }
        y += 50;
        Botao* pBotao = new Botao("Voltar");
        pBotao->moverBotao({440, y});
        incluirBotao(pBotao);
    }

}