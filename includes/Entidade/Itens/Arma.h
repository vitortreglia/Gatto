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
            Arma(IDs::IDs id, int forca);
            ~Arma();
            void setPersonagem(Personagem::Personagem* pPersonagem);
            Personagem::Personagem* getPersonagem();
            int getForca();
            void setAtacando(bool atk);
            bool getAtacando();
            void ataque();
            void atacar();
            void colisao(sf::Vector2f colisao, Entidade *pEntidade);
            void executar();
        };
    }
}

#endif //ARMA_H
