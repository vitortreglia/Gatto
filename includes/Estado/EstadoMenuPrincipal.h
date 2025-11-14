#ifndef ESTADOMENUINICIAL_H
#define ESTADOMENUINICIAL_H
#include "Estado.h"
#include "Menu/MenuPrincipal.h"


namespace Estados {
    class EstadoMenuPrincipal: public Estado {
    private:
        static EstadoMenuPrincipal* pEstadoMenu;
        Menu::MenuPrincipal* pMenu;
    private:
        EstadoMenuPrincipal();
    public:
        static EstadoMenuPrincipal* getEstadoMenuPrincipal(void* args);
        void iniciar(void* args);
        void sair(void* args);
        void tratarEventos();
        void atualizar();
        void desenhar();
    };
}


#endif //ESTADOMENUINICIAL_H
