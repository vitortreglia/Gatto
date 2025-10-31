#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"../Entidade.h"

namespace Entidade {
    namespace Personagem {
        class Personagem : public Entidade {
        protected:
            sf::Vector2f velocidade;
            sf::Vector2f vMax;
            sf::Vector2f aceleracao;
            sf::Vector2f deltaS;
            bool direita;
            bool andando;
            bool noChao;
            float dt;
        public:
            Personagem(float vel);
            virtual ~Personagem();
            void setVel(sf::Vector2f vel);
            sf::Vector2f getVel();
            void andar(const bool esq);
            void parar();
            void calculaVelocidade();
            void mover(sf::Vector2f pos);
            void estaNoChao(bool c);
            void colisao(sf::Vector2f colisao);
            virtual void mover();
            virtual void executar() = 0;
        };
    }
}


#endif //PERSONAGEM_H
