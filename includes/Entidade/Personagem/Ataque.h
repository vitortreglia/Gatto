#ifndef ARMA_H
#define ARMA_H
#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Personagem.h"


namespace Entidade {
        class Ataque {
        private:
            int dano;
            bool atacando;
            float tempoAtaque;
            float tMaxAtaque;
        public:
            Ataque(int forca);
            ~Ataque();
            int getForca();
            void setAtacando(bool atk);
            bool getAtacando();
            int getDano();
            void ataque(float tempoFrame);
        };
}

#endif //ARMA_H
