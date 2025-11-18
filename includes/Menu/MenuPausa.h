#ifndef MENUPAUSA_H
#define MENUPAUSA_H
#include "Menu.h"


namespace Menu {
    class MenuPausa: public Menu {
    private:
        Texto titulo;
    public:
        MenuPausa();
        ~MenuPausa();
        void criarBotoesPausa();
    };
}


#endif //MENUPAUSA_H
