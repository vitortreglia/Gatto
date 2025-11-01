#include "Entidade/Obstaculo/Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        Obstaculo::Obstaculo(bool dano, sf::Vector2f tamanho, float x, float y):
        danoso(dano),
        Entidade(tamanho, x, y) {
            //corpo.setRotation(15);
        }

        Obstaculo::~Obstaculo() {}
        void Obstaculo::executar() {
            desenhar();
        }

        void Obstaculo::colisao() {

        }

    }
}