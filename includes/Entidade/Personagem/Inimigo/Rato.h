#ifndef RATO_H
#define RATO_H
#include "Inimigo.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Rato : public Inimigo {
            private:
                bool atirouProjetil;
                bool podeAtirar;
                float tempoAtirar;
                float tempoAndar;
            public:
                Rato(float x, float y);
                ~Rato();
                bool getAtirou();
                void setAtirou(bool at);
                void atirar();
                void danificar(Jogador *pJ);
                void tomarDano(int dano);
                void mover();
                void executar();
            };
        }
    }
}

#endif //RATO_H
