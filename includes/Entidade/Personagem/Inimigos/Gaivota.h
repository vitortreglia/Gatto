#ifndef GAIVOTA_H
#define GAIVOTA_H

    #include "Entidade/Personagem/Inimigos/Inimigo.h"
#include <cmath>

namespace Entidade {
    namespace Personagem {
        namespace Inimigos {

            class Gaivota : public Inimigo {
            private:
                float tempo;
                float amplitude;
                float velocidadeHorizontal;
                float frequencia;
                float baseY;

            public:
                Gaivota(float x, float y);
                ~Gaivota();

                void verificaVidas();
                void mover();
                void executar();
            };
        }
    }
}

#endif