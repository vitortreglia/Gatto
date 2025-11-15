#include "Entidade/Obstaculo/Roseira.h"

namespace Entidade {
    namespace Obstaculo {
        Roseira::Roseira(bool dano, float x, float y):
        Obstaculo(dano, {200, 100}, x, y, IDs::Ente_IDs::Roseira),
        tempo(0.0f) {
            textura.setTextura("Data/Imagens/roseira.png");
            setTextura(&textura);
            atualizarTextura();
        }

        Roseira::~Roseira() {}

        void Roseira::atualizarTextura() {
            if (danoso)
                atualizarAnimacao({200, 0, 200, 100});
            else
                atualizarAnimacao({0, 0, 200, 100});
        }

        void Roseira::obstaculizar(Personagem::Jogador* pJog) {
            if (danoso) {
                pJog->tomarDano(1);
            }
        }

        void Roseira::executar() {
            tempo += tempoFrame;
            if (tempo > 2) {
                tempo = 0.0f;
                danoso = !danoso;
                atualizarTextura();
            }
        }

    }
}