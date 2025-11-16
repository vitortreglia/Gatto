#ifndef ROSEIRA_H
#define ROSEIRA_H
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Roseira : public Obstaculo {
        private:
            float tempo;
        public:
            Roseira(bool dano, float x, float y);
            ~Roseira();
            void atualizarTextura();
            void obstaculizar(Personagem::Jogador* pJog);
            void executar();
        };
    }
}

#endif //ROSEIRA_H
