#ifndef MENUINICIAL_H
#define MENUINICIAL_H
#include "Menu.h"


namespace Menu {
    class MenuPrincipal: public Menu {
    public:
        MenuPrincipal();
        ~MenuPrincipal();
        void criarBotoesMenuPrincipal();
    };
}


#endif //MENUINICIAL_H
