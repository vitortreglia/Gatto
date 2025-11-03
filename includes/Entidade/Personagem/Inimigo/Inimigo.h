#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Personagem/Jogador/Jogador.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Inimigo : public Personagem {
            protected:
                static Jogador* pJog;
            public:
                Inimigo(float vel, sf:: Vector2f tam, float px, float py, int vidas, IDs::IDs id);
                ~Inimigo();
                static void setJogador(Jogador* pJ);
                void verificaDistanciaJogador(sf::Vector2f distSeguir, sf::Vector2f distAtacar);
                void colisao(sf::Vector2f colisao, Entidade *pEntidade);
                void verificaVidas();
                virtual void mover();
                virtual void executar();
            };
        }
    }
}


#endif //INIMIGO_H
