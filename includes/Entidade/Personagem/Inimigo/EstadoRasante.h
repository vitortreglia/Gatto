
#ifndef GATTO_ESTADORASANTE_H
#define GATTO_ESTADORASANTE_H
#include "EstadoGaivota.h"
#include "SFML/System/Vector2.hpp"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class EstadoRasante : public EstadoGaivota {
            private:
                sf::Vector2f vetorAtaque;
                float tempo;
            public:
                EstadoRasante(Gaivota* pGav);
                ~EstadoRasante();
                void executar(float dt);
            };
        }
    }
}

#endif //GATTO_ESTADORASANTE_H