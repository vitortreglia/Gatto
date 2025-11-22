#ifndef ESTADOFIMDEJOGO_H
#define ESTADOFIMDEJOGO_H
#include "Estado.h"
#include "Menu/MenuFimDeJogo.h"


namespace Estados {
    class EstadoFimDeJogo: public Estado {
    private:
        static EstadoFimDeJogo* pEstadoF;
        Menu::MenuFimDeJogo* pMenu;
        int pontVencedor;
        string nome;
    private:
        EstadoFimDeJogo();
    public:
        static EstadoFimDeJogo* getEstadoFimDeJogo(void* args);
        void iniciar(void* args);
        void sair(void* args);
        void tratarEventos();
        void atualizar();
    };
}


#endif //ESTADOFIMDEJOGO_H
