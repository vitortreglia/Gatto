#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"../Entidade.h"

namespace Entidade {
    namespace Personagem {
        class Personagem : public Entidade {
        protected:
            int numVidas;
            bool vivo;
            sf::Vector2f velocidade;
            sf::Vector2f vMax;
            sf::Vector2f aceleracao;
            bool direita;
            bool andando;
            bool noChao;
        public:
            Personagem(float vel, sf::Vector2f tam, float px, float py, int vidas);
            virtual ~Personagem();
            void setVel(sf::Vector2f vel);
            sf::Vector2f getVel();
            void andar(const bool esq);
            void parar();
            void calculaVelocidade();
            void atualizarPos(sf::Vector2f pos);
            void atualizarPos();
            void estaNoChao(bool c);
            void colisao(sf::Vector2f colisao);
            virtual void verificaVidas() = 0;
            virtual void mover() = 0;
            virtual void executar() = 0;
        };
    }
}


#endif //PERSONAGEM_H
