#include "../../../includes/Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        Personagem::Personagem(sf::Vector2f vmax):
        Entidade(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f)),
        velMax(vmax),
        vel(sf::Vector2f(0.0f, 0.0f)),
        esquerda(true),
        andando(false)
        {}



    }
}