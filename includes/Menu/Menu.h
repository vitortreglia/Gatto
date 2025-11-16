#ifndef MENU_H
#define MENU_H
#include "Ente.h"
#include "Entidade/Botao/Botao.h"

namespace Menu {
    class Menu : public Ente{
    private:
        sf::RectangleShape fundo;
        std::vector<Entidade::Botao*> botoes;
        std::vector<Texto*> textos;
    public:
        Menu();
        ~Menu();
        void incluirBotao(Entidade::Botao* pB);
        void incluirTexto(Texto* pT);
        void executar();
    };
}
#endif //MENU_H
