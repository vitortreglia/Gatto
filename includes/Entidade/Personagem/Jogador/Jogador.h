#ifndef JOGADOR_H
#define JOGADOR_H
#include "../Personagem.h"
#include "Entidade/Itens/Arma.h"

namespace Entidade {
    namespace Personagem {
        class Jogador : public Personagem {
        private:
            bool podePular;
            Itens::Arma* pGarra;
        public:
            Jogador(Itens::Arma* pG);
            ~Jogador();
            void liberaPulo();
            void pular();
            void atacar();
            void verificaVidas();
            void mover();
            void executar();
        };
    }
}

#endif //JOGADOR_H
