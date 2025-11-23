#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"Entidade/Entidade.h"

namespace Entidade {
    namespace Personagem {
        class Personagem : public Entidade {
        protected:
            int numVidas;
            float vMax;
            bool direita;
            bool andando;
            bool noChao;
            bool sofrendoDano;
            float tempoDano;
            //bool vivo;
        public:
            Personagem(float vel, sf::Vector2f tam, float px, float py, int vidas);
            ~Personagem();
            void andar(const bool dir);
            void parar();
            const bool getDireita() const;
            void calculaVelocidade();
            void atualizarPos(sf::Vector2f pos);
            void atualizarPos();
            void estaNoChao(bool c);
            virtual void tomarDano(int dano);
            void lerDataBuffer();
            virtual void carregar(istream &entrada) = 0;
            void salvarDataBuffer();
            virtual void salvar(ostream& saida) = 0;
            virtual void verificaVidas() = 0;
            virtual void mover() = 0;
            virtual void executar() = 0;
        };
    }
}


#endif //PERSONAGEM_H
