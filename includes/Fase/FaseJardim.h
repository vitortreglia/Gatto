#ifndef FASE1_H
#define FASE1_H
#include "Fase.h"


namespace Fase {
    class FaseJardim : public Fase{
    private:
        const int maxInimRato;
        const int maxGiraGira;
        int numInimRato;
        int numGiraGira;
    public:
        FaseJardim(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2);
        ~FaseJardim();
    private:
        void criarGiraGira(float x, float y);
        void criarInimigoRato(float x, float y);
        void criarFaseJardim();
    };
}


#endif //FASE1_H
