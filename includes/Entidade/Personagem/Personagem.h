#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"../Entidade.h"

namespace Entidade {
    namespace Personagem {
        class Personagem : public Entidade {
        protected:
            int numVidas;
            sf::Vector2f vMax;
            float gravidade;
            sf::Vector2f deslocamento;
            bool direita;
            bool andando;
            bool noChao;
            bool sofrendoDano;
            float tempoDano;
            bool vivo;
        public:
            Personagem(float vel, sf::Vector2f tam, float px, float py, int vidas, IDs::IDs id);
            virtual ~Personagem();
            void andar(const bool esq);
            void parar();
            bool getDireita();
            void calculaVelocidade();
            void atualizarPos(sf::Vector2f pos);
            void atualizarPos();
            void estaNoChao(bool c);
            void tomarDano(int dano);
            void colisao(sf::Vector2f colisao, Entidade* pEntidade) = 0;
            virtual void verificaVidas() = 0;
            virtual void mover() = 0;
            virtual void executar() = 0;
        };
    }
}


#endif //PERSONAGEM_H
