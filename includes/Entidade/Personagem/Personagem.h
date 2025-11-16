#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"Entidade/Entidade.h"

namespace Entidade {
    namespace Personagem {
        class Personagem : public Entidade {
        protected:
            int numVidas;
            sf::Vector2f vMax;
            const float gravidade;
            sf::Vector2f deslocamento;
            bool direita;
            bool andando;
            bool noChao;
            bool sofrendoDano;
            float tempoDano;
            //bool vivo;
            bool voador;
        public:
            Personagem(float vel, sf::Vector2f tam, float px, float py, int vidas);
            ~Personagem();
            void andar(const bool dir);
            void parar();
            const bool getDireita() const;
            void calculaVelocidade();
            const sf::Vector2f getDeslocamento() const;
            void setDeslocamento(sf::Vector2f desl);
            void atualizarPos(sf::Vector2f pos);
            void atualizarPos();
            void estaNoChao(bool c);
            virtual void tomarDano(int dano);
            void setVoador(bool voador);
            virtual void verificaVidas() = 0;
            virtual void mover() = 0;
            virtual void executar() = 0;
        };
    }
}


#endif //PERSONAGEM_H
