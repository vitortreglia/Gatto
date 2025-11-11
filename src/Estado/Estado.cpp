#include "Estado/Estado.h"

#include "Gerenciador/GerenciadorEstados.h"

namespace Estados {
    void Estado::mudarEstado(Gerenciador::GerenciadorEstados *PGE, Estado *pE) {
        PGE->mudarEstado(pE);
    }
}
