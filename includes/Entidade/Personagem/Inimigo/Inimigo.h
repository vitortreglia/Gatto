#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade/Personagem/Personagem.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Inimigo : public Personagem {
            public:
                Inimigo(float vel, sf:: Vector2f tam, float px, float py, int vidas, IDs::IDs id);
                ~Inimigo();
                void colisao(sf::Vector2f colisao, Entidade *pEntidade);
                void verificaVidas();
                virtual void mover();
                virtual void executar();
            };
        }
    }
}


#endif //INIMIGO_H
