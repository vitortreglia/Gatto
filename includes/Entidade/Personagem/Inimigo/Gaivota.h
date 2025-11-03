#ifndef GAIVOTA_H
#define GAIVOTA_H

#include "Entidade/Personagem/Inimigo/Inimigo.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {

            class Gaivota : public Inimigo {
            private:
                float tempoMovimento;
                float amplitude;
                float frequencia;
                float baseY;
            public:
                Gaivota(float x, float y);
                ~Gaivota();

                //void verificaVidas();
                void mover();
                void executar();
            };
        }
    }
}

#endif