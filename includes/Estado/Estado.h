#ifndef ESTADO_H
#define ESTADO_H
#include "Observer/Observer.h"
#include <fstream>
namespace Gerenciador {
    class GerenciadorEstados;
}


namespace Estados {
    class Estado: public Observer {
    private:
        static Gerenciador::GerenciadorEstados* pGE;
    public:
        static void setGerenciadorEstados(Gerenciador::GerenciadorEstados* pG);
        virtual ~Estado() = default;

        void notificar();

        virtual void iniciar(void* args) = 0;
        virtual void sair(void* args) = 0;

        virtual void tratarEventos() = 0;

        virtual void atualizar() = 0;
        void mudarEstado(Estado* pE);
    };
}


#endif //ESTADO_H
