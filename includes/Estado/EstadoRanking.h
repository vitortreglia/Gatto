#ifndef ESTADORANKING_H
#define ESTADORANKING_H
#include "Estado.h"
#include "Menu/MenuRanking.h"


namespace Estados {
    class EstadoRanking: public Estado {
    private:
        static EstadoRanking* pEstadoRanking;
        Menu::MenuRanking* pMenu;
    private:
        EstadoRanking();
    public:
        static EstadoRanking* getEstadoRanking(void* args);
        void iniciar(void* args);
        void sair(void* args);
        void tratarEventos();
        void atualizar();
    };
}


#endif //ESTADORANKING_H
