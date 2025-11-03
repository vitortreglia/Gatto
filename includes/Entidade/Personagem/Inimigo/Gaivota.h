#ifndef GAIVOTA_H
#define GAIVOTA_H

#include "Entidade/Personagem/Inimigo/Inimigo.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {

            class Gaivota : public Inimigo {
            private:
                float tempo;
                float amplitude;
                float velocidadeHorizontal;
                float frequencia;
                float baseY;
                bool direcao;

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