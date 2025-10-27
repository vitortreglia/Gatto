#include "Entidade/Obstaculo/Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        Obstaculo::Obstaculo():
        danoso(false),
        Entidade(sf::Vector2f(800.0f, 100.0f), sf::Vector2f(0.0f, 550.0f)) {
            //corpo.rotate(-30);
        }

        Obstaculo::~Obstaculo() {}

        void Obstaculo::colisao() {

        }

    }
}