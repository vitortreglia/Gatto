#include "Estado/EstadoJogo.h"
#include "Fase/FaseJardim.h"

namespace Estados {
    EstadoJogo* EstadoJogo::pEstadoJogo(nullptr);

    EstadoJogo::EstadoJogo():
    pFase(nullptr)
    {}

    EstadoJogo *EstadoJogo::getEstadoJogo(void* args) {
        if (!pEstadoJogo)
            pEstadoJogo = new EstadoJogo();

        if (args)
            pEstadoJogo->iniciar(args);

        return pEstadoJogo;
    }

    //args:
    //[0]: 1 = novo jogo 2 = carregar jogo
    //[1]: 1 = fase jardim 2 = fase cidade
    //[2]: num jogs (1 ou 2)
    void EstadoJogo::iniciar(void *args) {
        int* arg = (int*)args;
        if (arg[0] == 1) {
            if (pFase)
                delete pFase;
            if (arg[1] == 1) {
                pFase = new Fase::FaseJardim();
            }
        }
    }

    void EstadoJogo::sair(void *args) {

    }

    void EstadoJogo::atualizar() {
        pFase->executar();
    }

    void EstadoJogo::desenhar() {

    }

}
