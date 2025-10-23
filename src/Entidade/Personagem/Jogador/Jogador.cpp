#include "Entidade/Personagem/Jogador/Jogador.h"
namespace Entidade {
    namespace Personagem {
        Jogador::Jogador():
        Personagem(sf::Vector2f(100.0f, 100.0f))
        {}

        Jogador::~Jogador() {}
        void Jogador::atualizar() {
            atualizarPos();
            desenhar();
        }

    }
}