#include "Gerenciador/GerenciadorEstados.h"

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
        Estados::Estado::setGerenciadorEvento();
        mudarEstado(Estados::EstadoMenuPrincipal::getEstadoMenuPrincipal(static_cast<void*>(args)));
        //mudarEstado(Estados::EstadoPausa::getEstadoPausa(NULL));
    }


    void GerenciadorEstados::atualizar() {
        pEstado->atualizar();
    }

}
