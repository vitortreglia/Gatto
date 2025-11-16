#ifndef RATO_H
#define RATO_H
#include "Inimigo.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Rato : public Inimigo {
            private:
                float tempoAndar;
                string imgRato;
            public:
                Rato(float x, float y);
                ~Rato();
                void danificar(Jogador *pJ);
                void tomarDano(int dano);
                void mover();
                void executar();
            };
        }
    }
}

#endif //RATO_H
