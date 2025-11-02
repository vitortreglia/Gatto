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
            float tempoAtaque;
            float tMaxAtaque;
        public:
            Arma(IDs::IDs id);
            ~Arma();
            void setPersonagem(Personagem::Personagem* pPersonagem);
            Personagem::Personagem* getPersonagem();
            void setAtacando(bool atk);
            bool getAtacando();
            void ataque();
            void atacar();
            void colisao(sf::Vector2f colisao);
            void executar();
        };
    }
}

#endif //ARMA_H
