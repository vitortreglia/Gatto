#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade/Personagem/Personagem.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Inimigo : public Personagem {
            public:
                Inimigo(float px, float py);
                ~Inimigo();
                void colisao(sf::Vector2f colisao, Entidade *pEntidade) override;
                void verificaVidas();
                void mover();
                void executar();
            };
        }
    }
}


#endif //INIMIGO_H
