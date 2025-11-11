#include "Gerenciador/GerenciadorEstados.h"

namespace Gerenciador {
    GerenciadorEstados::GerenciadorEstados() {
        int args[] = {1, 1, 1};
        mudarEstado(Estados::EstadoJogo::getEstadoJogo(static_cast<void*>(args)));
    }

    void GerenciadorEstados::mudarEstado(Estados::Estado *pE) {
        pEstado = pE;
    }

    void GerenciadorEstados::atualizar() {
        pEstado->atualizar();
    }

    void GerenciadorEstados::desenhar() {

    }

}