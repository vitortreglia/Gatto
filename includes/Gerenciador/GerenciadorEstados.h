#ifndef GERENCIADORESTADOS_H
#define GERENCIADORESTADOS_H
#include "Estado/EstadoJogo.h"


namespace Gerenciador {
    class GerenciadorEstados {
    private:
        Estados::Estado* pEstado;

    public:
        GerenciadorEstados();
        ~GerenciadorEstados();

        //void setLimitesCamera();

        void atualizar();
        void desenhar();

        void mudarEstado(Estados::Estado* pE);

    };
}

#endif //GERENCIADORESTADOS_H
