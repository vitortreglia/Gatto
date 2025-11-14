#ifndef MENU_H
#define MENU_H
#include "Ente.h"
#include "Entidade/Botao/Botao.h"

namespace Menu {
    class Menu : public Ente{
    private:
        sf::RectangleShape fundo;
        std::vector<Entidade::Botao*> botoes;
    public:
        Menu(IDs::Ente_IDs id);
        ~Menu();
        void incluirBotao(Entidade::Botao* pB);
        void executar();
    };
}
#endif //MENU_H
