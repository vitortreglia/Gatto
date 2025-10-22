#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"../Entidade.h"

namespace Entidade {
    namespace Personagem {
        class Personagem : public Entidade {
        protected:
            sf::Vector2f vel;
            sf::Vector2f velMax;
            bool esquerda;
            bool andando;
        public:
            Personagem(sf::Vector2f vmax);
            ~Personagem();
            void setVel(sf::Vector2f vel);
            sf::Vector2f getVel();
            void setVelMax(sf::Vector2f vMax);
            sf::Vector2f getVelMax();
            void andar();
            void parar();
            void setEsquerda(bool esq);
            void atualizarPos();
            virtual void atualizar() = 0;
        };
    }
}


#endif //PERSONAGEM_H
