#ifndef JOGADOR_H
#define JOGADOR_H
#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Texto.h"
#include "../Ataque.h"
#include "Entidade/Itens/Peixe.h"
#include "Entidade/Itens/Projetil.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"

namespace Entidade {
    namespace Personagem {
        class Jogador : public Personagem, public Ataque {
        private:
            bool podePular;
            int peixes;
            float deslocAtaque;
            Texto interface;
        public:
            Jogador();
            ~Jogador();
            void liberaPulo();
            void pular(float multiplicador);
            void coletarPeixe(Itens::Peixe* pPeixe);
            void perderPeixe();
            void colidir(Inimigo::Inimigo* pInimigo, sf::Vector2f colisao);
            void colidir(sf::Vector2f colisao);
            void verificaVidas();
            void mover();
            void executar();
        };
    }
}

#endif //JOGADOR_H
