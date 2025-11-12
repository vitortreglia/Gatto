#ifndef ESTADO_H
#define ESTADO_H
#include "Ente_IDs.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Observer/Observer.h"

namespace Gerenciador {
    class GerenciadorEstados;
}


namespace Estados {
    class Estado: public Observer {
    protected:
        static Gerenciador::GerenciadorEvento* pGEvento;
    private:
        static Gerenciador::GerenciadorEstados* pGE;
    public:
        static void setGerenciadorEstados(Gerenciador::GerenciadorEstados* pG);
        static void setGerenciadorEvento();
        virtual ~Estado() = default;

        void notificar();

        virtual void iniciar(void* args) = 0;
        virtual void sair(void* args) = 0;

        virtual void tratarEventos() = 0;

        virtual void atualizar() = 0;
        virtual void desenhar() = 0;
        void mudarEstado(Estado* pE);
    };
}


#endif //ESTADO_H
