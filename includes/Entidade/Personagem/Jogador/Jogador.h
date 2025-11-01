#ifndef JOGADOR_H
#define JOGADOR_H
#include "../Personagem.h"

namespace Entidade {
    namespace Personagem {
        class Jogador : public Personagem {
        private:
            bool podePular;
        public:
            Jogador();
            ~Jogador();
            void liberaPulo();
            void pular();
            void verificaVidas();
            void mover();
            void executar();
        };
    }
}

#endif //JOGADOR_H
