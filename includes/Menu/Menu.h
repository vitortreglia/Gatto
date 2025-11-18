#ifndef MENU_H
#define MENU_H
#include "Ente.h"
#include "Entidade/Botao/Botao.h"

namespace Menu {
    class Menu : public Ente{
    protected:
        sf::RectangleShape fundo;
        std::vector<Entidade::Botao*> botoes;
        std::vector<Texto*> textos;
        int selecao;
    public:
        Menu();
        ~Menu();
        void incluirBotao(Entidade::Botao* pB);
        void incluirTexto(Texto* pT);
        void executar();
        void proximo();
        void anterior();
        int getSelecao();
    };
}
#endif //MENU_H
