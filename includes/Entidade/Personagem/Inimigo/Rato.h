#ifndef RATO_H
#define RATO_H
#include "Inimigo.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Rato : public Inimigo {
            private:
                float tempoAndar;
            public:
                Rato(float x, float y);
                ~Rato();
                void danificar(Jogador *pJ);
                void tomarDano(int dano);
                void mover();
                void executar();
                void lerDataBuffer();
                void carregar(istream &entrada);
                void salvarDataBuffer();
                void salvar(ostream& saida);
            };
        }
    }
}

#endif //RATO_H
