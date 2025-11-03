#include "Entidade/Personagem/Inimigos/Inimigo.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigos {

            Inimigo::Inimigo():Personagem(
                0.f,
                sf::Vector2f(0.f, 0.f),
                0.f, 0.f,
                1,
                IDs::IDs::vazio)
            {
            }

            Inimigo::~Inimigo() {
            }
        }
    }
}