#include "Entidade/Itens/ArmaInimigo.h"

#include "Entidade/Itens/Arma.h"

namespace Entidade {
    namespace Itens {
        ArmaInimigo::ArmaInimigo(IDs::IDs id, int forca) : Arma(id, forca) {

        }
        void ArmaInimigo::executar(){

            if (getAtacando())
                atacar();
        }

        void ArmaInimigo::atacar() {

            desenhar();
            if (tempoAtaque == 0.0) {
                ataque();
            }

            tempoAtaque += tempoFrame;

            if (tempoAtaque > tMaxAtaque) {
                setAtacando(false);
                tempoAtaque = 0.0;
                setPosicao ({-1000.0, -1000.0});
            }
        }
    }
}