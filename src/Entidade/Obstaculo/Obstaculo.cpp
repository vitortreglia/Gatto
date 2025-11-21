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

        void Obstaculo::lerDataBuffer() {
            Entidade::lerDataBuffer();
            entrada >> danoso;
        }

        void Obstaculo::salvarDataBuffer() {
            Entidade::salvarDataBuffer();
            buffer << danoso << ' ';
        }

    }
}