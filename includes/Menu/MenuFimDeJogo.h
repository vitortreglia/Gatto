#ifndef MENUFIMDEJOGO_H
#define MENUFIMDEJOGO_H
#include "Menu.h"
#include "UI/CaixaDeTexto.h"

namespace Menu {
    class MenuFimDeJogo : public Menu {
    private:
        Animacao fundo;
        Texto titulo;
        CaixaDeTexto entrada;
    public:
        MenuFimDeJogo(int i);
        ~MenuFimDeJogo();
        void CriarMenuFimDeJogo();
        bool getDigitando();
        void digitar();
        string getNome();
        void pararDigitar();
        bool tratarCliques(sf::Vector2f c);
        void executar();
    };
}

#endif //MENUFIMDEJOGO_H
