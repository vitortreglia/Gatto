#ifndef ARMA_H
#define ARMA_H
#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Personagem.h"


namespace Entidade {
    namespace Itens {
        class Arma : public Entidade {
        private:
            int dano;
            Personagem::Personagem* pPersonagem;
            bool atacando;
        public:
            Arma(IDs::IDs id);
            ~Arma();
            void setPersonagem(Personagem::Personagem* pPersonagem);
            Personagem::Personagem* getPersonagem();
            void estaAtacando(bool atk);
            void ataque();
            void colisao(sf::Vector2f colisao);
            void executar();
        };
    }
}

#endif //ARMA_H
