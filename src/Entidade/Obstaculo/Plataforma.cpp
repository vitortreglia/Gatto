#include "Entidade/Obstaculo/Plataforma.h"
namespace Entidade {
    namespace Obstaculo {
        Plataforma::Plataforma(float x, float y):
        Obstaculo(false, sf::Vector2f(100,50), x, y, IDs::Ente_IDs::Plataforma) {
            corpo.setFillColor(sf::Color::Blue);
        }

        Plataforma::~Plataforma() {

        }

        void Plataforma::obstaculizar(Personagem::Jogador* pJog) {

        }

        void Plataforma::executar() {
            //desenhar();
        }


    }
}