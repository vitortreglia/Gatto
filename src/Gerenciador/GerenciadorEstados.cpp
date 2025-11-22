#include "Gerenciador/GerenciadorEstados.h"

#include "Estado/EstadoFimDeJogo.h"
#include "Estado/EstadoMenuPrincipal.h"
#include "Estado/EstadoPausa.h"

namespace Gerenciador {
    GerenciadorEstados::GerenciadorEstados() {
    }

    void GerenciadorEstados::mudarEstado(Estados::Estado *pE) {
        pEstado = pE;
    }

    void GerenciadorEstados::iniciar() {
        int args[] = {1, 1, 1};
        Estados::Estado::setGerenciadorEstados(this);
        mudarEstado(Estados::EstadoMenuPrincipal::getEstadoMenuPrincipal(static_cast<void*>(args)));
    }


    void GerenciadorEstados::atualizar() {
        pEstado->atualizar();
    }

}
