#include "Entidade/Itens/Peixe.h"

namespace Entidade {
    namespace Itens {
        Peixe::Peixe(float x, float y):
        Entidade({50, 50}, x, y, IDs::IDs::ItemPeixe),
        movimento(60),
        sentido(true)
        {}

        Peixe::~Peixe() {}

        void Peixe::mover() {
            movimento -= 1;
            if (sentido) {
                setPosicao({getPosicao().x, getPosicao().y - 1});
            } else {
                setPosicao({getPosicao().x, getPosicao().y + 1});
            }
            if (movimento == 1) {
                movimento = 60;
                sentido = !sentido;
            }
        }

        void Peixe::colisao(sf::Vector2f colisao, Entidade *pEntidade) {
            pEntidade->colisao({0, 0}, this);
        }

        void Peixe::executar() {
            mover();
            desenhar();
        }


    }
}