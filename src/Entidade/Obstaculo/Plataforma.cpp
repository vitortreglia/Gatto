#include "Entidade/Obstaculo/Plataforma.h"
namespace Entidade {
    namespace Obstaculo {
        Plataforma::Plataforma(sf::Vector2f tam, float x, float y):
        Obstaculo(false, tam, x, y) {
            corpo.setFillColor(sf::Color::Blue);
        }

        Plataforma::~Plataforma() {

        }

        void Plataforma::obstaculizar() {

        }

        void Plataforma::executar() {
            desenhar();
        }


    }
}