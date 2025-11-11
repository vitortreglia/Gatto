#ifndef ESTADO_H
#define ESTADO_H
#include "Ente_IDs.h"

namespace Gerenciador {
    class GerenciadorEstados;
}


namespace Estados {
    class Estado {
    public:
        virtual ~Estado() = default;

        virtual void iniciar(void* args) = 0;
        virtual void sair(void* args) = 0;

        virtual void atualizar() = 0;
        virtual void desenhar() = 0;

        void mudarEstado(Gerenciador::GerenciadorEstados* PGE, Estado* pE);
    };
}


#endif //ESTADO_H
