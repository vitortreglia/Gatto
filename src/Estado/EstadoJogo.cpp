#include "Estado/EstadoJogo.h"

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
    //[1]: num jogs (1 ou 2)
    //[2]: 1 = fase jardim 2 = fase cidade
    void EstadoJogo::iniciar(void *args) {
        int* arg = (int*)args;
        if (arg[1] == 1) {

        }
    }

    void EstadoJogo::sair(void *args) {

    }

    void EstadoJogo::atualizar() {

    }

    void EstadoJogo::desenhar() {

    }

}