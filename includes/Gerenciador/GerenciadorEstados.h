#ifndef GERENCIADORESTADOS_H
#define GERENCIADORESTADOS_H
#include "Estado/EstadoJogo.h"
#include "Observer/Observer.h"

/*  Gerenciador de Estados
*
*      Implementacao do padrao State realizada utilizando como referencia
*       o livro Padroes de Projeto, de Erich Gamma, Richard Helm, Ralph Johnson
*       e John Vlissides
*
*/

namespace Gerenciador {
    class GerenciadorEstados {
    private:
        Estados::Estado* pEstado;

    public:
        GerenciadorEstados();
        ~GerenciadorEstados();

        //void setLimitesCamera();
        void iniciar();

        void atualizar();
        void desenhar();

        void mudarEstado(Estados::Estado* pE);

    };
}

#endif //GERENCIADORESTADOS_H
