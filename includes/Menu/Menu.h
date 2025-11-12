#ifndef MENU_H
#define MENU_H
#include "Ente.h"
#include "Entidade/Botao/Botao.h"

namespace Menu {
    class Menu : public Ente{
    private:
        sf::RectangleShape fundo;
        std::vector<Botao*> botoes;
    public:
        Menu(IDs::Ente_IDs id);
        ~Menu();
        void incluirBotao(Botao* pB);
        void executar();
    };
}
#endif //MENU_H
