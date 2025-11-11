#ifndef GERENCIADORESTADOS_H
#define GERENCIADORESTADOS_H
#include "Estado/Estado.h"


namespace Gerenciador {
    class GerenciadorEstados {
    private:
        Estados::Estado* pEstado;
    public:
        GerenciadorEstados();
        ~GerenciadorEstados();

        void atualizar();
        void desenhar();

        void mudarEstado(Estados::Estado* pE);

    };
}

#endif //GERENCIADORESTADOS_H
