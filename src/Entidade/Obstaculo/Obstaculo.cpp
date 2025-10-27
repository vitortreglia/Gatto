#include "Entidade/Obstaculo/Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        Obstaculo::Obstaculo():
        danoso(false),
        Entidade(sf::Vector2f(600.0f, 100.0f), sf::Vector2f(0.0f, 400.0f))
        {}

        Obstaculo::~Obstaculo() {}

        void Obstaculo::colisao() {

        }

    }
}