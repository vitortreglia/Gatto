#ifndef MENU_H
#define MENU_H
#include "Ente.h"
#include "UI/Botao.h"

namespace Menu {
    class Menu : public Ente{
    protected:
        sf::RectangleShape fundo;
        std::vector<Botao*> botoes;
        std::vector<Texto*> textos;
        int selecao;
    public:
        Menu();
        ~Menu();
        void incluirBotao(Botao* pB);
        void incluirTexto(Texto* pT);
        virtual void executar();
        void proximo();
        void anterior();
        int getSelecao();
        virtual bool tratarCliques(sf::Vector2f c);
    };
}
#endif //MENU_H
