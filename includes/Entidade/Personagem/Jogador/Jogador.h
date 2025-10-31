#ifndef JOGADOR_H
#define JOGADOR_H
#include "../Personagem.h"

namespace Entidade {
    namespace Personagem {
        class Jogador : public Personagem {
        private:
        public:
            Jogador();
            ~Jogador();
            void pular();
            void executar();
        };
    }
}

#endif //JOGADOR_H
