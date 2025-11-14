#ifndef FASE1_H
#define FASE1_H
#include "Fase.h"


namespace Fase {
    class FaseJardim : public Fase{
    private:
        const int maxInimGaivota;
        const int maxInimRato;
    public:
        FaseJardim(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2);
        ~FaseJardim();
    private:
        void criarPlataformaMovel(float x, float y, bool direcao);
        void criarPlataformaGiratoria(float x, float y);
        void criarInimigoRato(float x, float y);
        void criarFaseJardim();
    };
}


#endif //FASE1_H
