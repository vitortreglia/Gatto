#include "../../../../includes/Entidade/Personagem/Jogador/Jogador.h"
namespace Entidade {
    namespace Personagem {
        Jogador::Jogador():
        corpo(sf::Vector2f(50.0f, 50.0f)),
        vel(sf::Vector2f(0.1f, 0.1f)) {
            corpo.setPosition(50.0, 50.0);
        }
        Jogador::~Jogador() {}

        void Jogador::move() {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                corpo.move(-vel.x, 0.0);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                corpo.move(vel.x, 0.0);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                corpo.move(0.0, -vel.y);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                corpo.move(0.0, vel.y);
            }
        }

        sf::RectangleShape* Jogador::getCorpo() {
            return &corpo;
        }
    }
}