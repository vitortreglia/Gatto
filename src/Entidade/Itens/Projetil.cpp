#include "Entidade/Itens/Projetil.h"

namespace Entidade {
    namespace Itens {
        Projetil::Projetil(float x, float y, bool direita) :
        Entidade({20.0f, 20.0f}, x, y, IDs::Ente_IDs::Projetil),
        tempoLancamento(0.0f)
        {
            this->direita = direita;
        }

        Projetil::~Projetil() {}

        void Projetil::mover() {
            tempoLancamento += tempoFrame;
            if (tempoLancamento < 4.0f) {
                if (direita) {
                    setPosicao({getPosicao().x + 300 * tempoFrame, getPosicao().y});
                } else {
                    setPosicao({getPosicao().x - 300 * tempoFrame, getPosicao().y});
                }
            } else {
                setAtivo(false);
            }
        }

        void Projetil::executar() {
            mover();
            desenhar();
        }

    }
}