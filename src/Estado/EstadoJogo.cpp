#include "Estado/EstadoJogo.h"

#include "Estado/EstadoPausa.h"
#include "Fase/FaseJardim.h"

namespace Estados {
    EstadoJogo* EstadoJogo::pEstadoJogo(nullptr);

    EstadoJogo::EstadoJogo():
    pFase(nullptr)
    {}

    EstadoJogo *EstadoJogo::getEstadoJogo(void* args) {
        if (!pEstadoJogo)
            pEstadoJogo = new EstadoJogo();

        pEstadoJogo->iniciar(args);

        return pEstadoJogo;
    }

    //args:
    //[0]: 1 = novo jogo 2 = carregar jogo
    //[1]: 1 = fase jardim 2 = fase cidade
    //[2]: num jogs (1 ou 2)
    void EstadoJogo::iniciar(void *args) {
        if (args) {
            int* arg = (int*)args;
            if (arg[0] == 1) {
                if (pFase)
                    delete pFase;
                if (arg[1] == 1) {
                    pFase = new Fase::FaseJardim();
                }
            }
        }
        pGEvento->inscrever(this);
        pFase->inscreverObservadores();
    }

    void EstadoJogo::sair(void *args) {
        pGEvento->desinscrever(this);
        pFase->desinscreverObservadores();
        mudarEstado(EstadoPausa::getEstadoPausa(NULL));
    }

    void EstadoJogo::tratarEventos() {
        set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();

        if (teclasSoltas.count(sf::Keyboard::P)) {
            sair(NULL);
        }
    }

    void EstadoJogo::atualizar() {
        pFase->executar();
    }

    void EstadoJogo::desenhar() {

    }

}
