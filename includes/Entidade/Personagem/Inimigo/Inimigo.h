#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        class Jogador;

        namespace Inimigo {
            class Inimigo : public Personagem {
            protected:
                int nivelMaldade;
            public:
                Inimigo(int nMaldade, float vel, sf:: Vector2f tam, float px, float py, int vidas, IDs::Ente_IDs id);
                ~Inimigo();

                void verificaVidas();
                virtual void danificar(Jogador* pJ) = 0;
                virtual void mover() = 0;
                virtual void executar() = 0;
            };
        }
    }
}


#endif //INIMIGO_H
