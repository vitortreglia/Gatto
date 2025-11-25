#include "Gerenciador/GerenciadorEstados.h"
#include "Estado/EstadoMenuPrincipal.h"
#include "Estado/EstadoRanking.h"

namespace Gerenciador {
    GerenciadorEstados::GerenciadorEstados() {
    }

    void GerenciadorEstados::mudarEstado(Estados::Estado *pE) { // faz a troca do estado atual do jogo
        pEstado = pE; // atualizar passa a chamar o ponteiro desse novo estado
    }

    void GerenciadorEstados::iniciar() { // prepara o sistema de estados e inicia no menu principal
        int args[] = {1, 1, 1};
        Estados::Estado::setGerenciadorEstados(this);
        mudarEstado(Estados::EstadoMenuPrincipal::getEstadoMenuPrincipal(static_cast<void*>(args)));
    }

    void GerenciadorEstados::atualizar() {
        pEstado->atualizar();
    }

}
