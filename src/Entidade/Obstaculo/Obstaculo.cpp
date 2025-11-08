#include "Entidade/Obstaculo/Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        Obstaculo::Obstaculo(bool dano, sf::Vector2f tamanho, float x, float y, IDs::IDs id):
        danoso(dano),
        Entidade(tamanho, x, y, id) {
            //corpo.setRotation(15);
        }

        Obstaculo::~Obstaculo() {}
        void Obstaculo::executar() {
            desenhar();
        }

    }
}