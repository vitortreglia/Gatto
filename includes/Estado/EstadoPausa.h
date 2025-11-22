#ifndef ESTADOPAUSA_H
#define ESTADOPAUSA_H
#include "Estado.h"
#include "Menu/MenuPausa.h"


namespace Estados {
    class EstadoPausa : public Estado {
    private:
        static EstadoPausa* pEstadoPausa;
        Menu::MenuPausa* pMenuPausa;
    private:
        EstadoPausa();
    public:
        static EstadoPausa* getEstadoPausa(void* args);
        void iniciar(void* args);
        void sair(void* args);
        void tratarEventos();
        void atualizar();
    };
}


#endif //ESTADOPAUSA_H
