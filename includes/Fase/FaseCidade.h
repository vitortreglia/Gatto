#ifndef FASECIDADE_H
#define FASECIDADE_H
#include "Fase.h"


namespace Fase {
    class FaseCidade : public Fase {
    private:
        const int maxInimGaivota;
        const int maxChefoes;
    public:
        FaseCidade(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2);
        ~FaseCidade();
    protected:
        void criarProjetil(float x, float y, bool direita);
        void criarChefao(float x, float y);
        void criarRoseira(float x, float y);
        void criarFaseCidade();
    };
}


#endif //FASECIDADE_H
