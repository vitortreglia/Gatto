#include "Entidade/Itens/Peixe.h"

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Entidade {
    namespace Itens {
        Peixe::Peixe(float x, float y):
        Entidade({50, 50}, x, y),
        movimento(60),
        sentido(true) {
            textura.inserirTextura("base", "Data/Imagens/peixe.png");
            textura.setAnimacao("base");
        }

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

        void Peixe::executar() {
            textura.animar(false);
            mover();
        }


    }
}
