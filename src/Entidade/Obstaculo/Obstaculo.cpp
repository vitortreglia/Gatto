#include "Entidade/Obstaculo/Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        Obstaculo::Obstaculo():
        danoso(false),
        Entidade(sf::Vector2f(800.0f, 100.0f), 100.0f, 500.0f) {
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