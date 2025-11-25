#include "Estado/Estado.h"

#include "Gerenciador/GerenciadorEstados.h"

namespace Estados {
    Gerenciador::GerenciadorEstados* Estado::pGE(nullptr);

    void Estado::setGerenciadorEstados(Gerenciador::GerenciadorEstados *pG) {
        //registra o gerenciador na classe base - habilita transições de estado
        if (pG)
            pGE = pG;
    }

    void Estado::mudarEstado(Estado *pE) {
        // chama o gerenciador pra trocar o estado atual
        pGE->mudarEstado(pE);
    }

    void Estado::notificar() {
        // chama tratar eventos pra decidir o que fazer com as teclas/cliques
        tratarEventos();
    }

}
