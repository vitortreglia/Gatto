#include "Entidade/Obstaculo/Roseira.h"

namespace Entidade {
    namespace Obstaculo {
        Roseira::Roseira(bool dano, float x, float y):
        Obstaculo(dano, {200, 100}, x, y),
        tempo(0.0f) {
            textura.inserirTextura("base", "Data/Imagens/roseira.png");
            textura.setAnimacao("base");
            atualizarTextura();
        }

        Roseira::~Roseira() {}

        void Roseira::atualizarTextura() {
            if (danoso)
                corpo.setTextureRect({200, 0, 200, 100});
            else
                corpo.setTextureRect({0, 0, 200, 100});
        }

        void Roseira::obstaculizar(Personagem::Jogador* pJog) {
            if (danoso) {
                pJog->tomarDano(1);
                pJog->pular(0.5);
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