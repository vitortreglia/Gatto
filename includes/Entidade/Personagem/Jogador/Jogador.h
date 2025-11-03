#ifndef JOGADOR_H
#define JOGADOR_H
#include "../Personagem.h"
#include "Entidade/Texto.h"
#include "Entidade/Itens/Arma.h"

namespace Entidade {
    namespace Personagem {
        class Jogador : public Personagem {
        private:
            bool podePular;
            Itens::Arma* pGarra;
            int peixes;
            Texto interface;
        public:
            Jogador(Itens::Arma* pG);
            ~Jogador();
            void liberaPulo();
            void pular(float multiplicador);
            void atacar();
            void colisao(sf::Vector2f colisao, Entidade *pEntidade);
            void verificaVidas();
            void mover();
            void executar();
        };
    }
}

#endif //JOGADOR_H
