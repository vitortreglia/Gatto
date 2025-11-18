#include "Entidade/Itens/Projetil.h"

namespace Entidade {
    namespace Itens {
        Projetil::Projetil() :
        Entidade({20.0f, 20.0f}, 0, 0),
        tempoLancamento(0.0f)
        {
            setAtivo(false);
        }

        Projetil::~Projetil() {}

        void Projetil::setDirecao(bool dir) {
            direita = dir;
        }

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