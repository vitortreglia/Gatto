#include "Estado/EstadoJogo.h"

#include "Estado/EstadoPausa.h"
#include "Fase/FaseJardim.h"

namespace Estados {
    EstadoJogo* EstadoJogo::pEstadoJogo(nullptr);

    EstadoJogo::EstadoJogo():
    pFase(nullptr),
    pJog1(nullptr),
    pJog2(nullptr)
    {}

    EstadoJogo *EstadoJogo::getEstadoJogo(void* args) {
        if (!pEstadoJogo)
            pEstadoJogo = new EstadoJogo();

        pEstadoJogo->iniciar(args);

        return pEstadoJogo;
    }

    //args:
    //[0]: num jogs (1 ou 2)
    //[1]: 1 = novo jogo 2 = carregar jogo
    //[2]: 1 = fase jardim 2 = fase cidade
    void EstadoJogo::iniciar(void *args) {
        if (args) {
            int* arg = (int*)args;

            if (pJog1) {
                delete pJog1;
                pJog1 = nullptr;
            }
            if (pJog2) {
                delete pJog2;
                pJog2 = nullptr;
            }

            pJog1 = new Entidade::Personagem::Jogador(1);
            if (arg[0] == 2) {
                pJog2 = new Entidade::Personagem::Jogador(2);
            }
            if (arg[1] == 1) {
                if (pFase)
                    delete pFase;
                if (arg[1] == 1) {
                    pFase = new Fase::FaseJardim(pJog1, pJog2);
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
