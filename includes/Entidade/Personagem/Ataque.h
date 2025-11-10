#ifndef ARMA_H
#define ARMA_H
#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Personagem.h"


namespace Entidade {
        class Ataque {
        protected:
            int dano;
            bool atacando;
            bool podeAtacar;
            float tempoAtaque;
            float tMaxAtaque;
        public:
            Ataque(int forca);
            ~Ataque();
            int getForca();
            void atacar();
            bool getAtacando();
            void liberaAtaque();
            int getDano();
            void ataque(float tempoFrame);
        };
}

#endif //ARMA_H
