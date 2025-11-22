#include "Estado/Estado.h"

#include "Gerenciador/GerenciadorEstados.h"

namespace Estados {
    Gerenciador::GerenciadorEstados* Estado::pGE(nullptr);

    void Estado::setGerenciadorEstados(Gerenciador::GerenciadorEstados *pG) {
        if (pG)
            pGE = pG;
    }

    void Estado::mudarEstado(Estado *pE) {
        pGE->mudarEstado(pE);
    }

    void Estado::notificar() {
        tratarEventos();
    }

}
