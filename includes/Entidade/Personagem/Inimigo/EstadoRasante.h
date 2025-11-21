
#ifndef GATTO_ESTADORASANTE_H
#define GATTO_ESTADORASANTE_H
#include "EstadoGaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "SFML/System/Vector2.hpp"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class EstadoRasante : public EstadoGaivota {
            private:
                sf::Vector2f vetorAtaque;
                float tempo;
            public:
                EstadoRasante(Gaivota* pGav, Jogador* pJog);
                ~EstadoRasante();
                void executar(float dt);
                sf::Vector2f getVetorAtaque();
                float getTempo();
                void setVetorAtaque(sf::Vector2f VA);
                void setTempo(float t);
            };
        }
    }
}

#endif //GATTO_ESTADORASANTE_H