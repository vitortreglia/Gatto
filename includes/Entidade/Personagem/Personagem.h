#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"../Entidade.h"

namespace Entidade {
    namespace Personagem {
        class Personagem : public Entidade {
        protected:
            sf::Vector2f velocidade;
            bool esquerda;
            bool andando;
            float dt;
        public:
            Personagem(sf::Vector2f vel);
            virtual ~Personagem();
            void setVel(sf::Vector2f vel);
            sf::Vector2f getVel();
            void andar(const bool esq);
            void parar();
            void atualizarPos();
            virtual void atualizar() = 0;
        };
    }
}


#endif //PERSONAGEM_H
