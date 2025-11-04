#ifndef FASE1_H
#define FASE1_H
#include "Fase.h"


namespace Fase {
    class FaseJardim : public Fase{
    private:
        const int maxInimMedios;
        const int maxInimFaceis;
    public:
        FaseJardim();
        ~FaseJardim();
    private:
        void criarPlataformaMovel(float x, float y, bool direcao);
        void criarPlataformaGiratoria(float x, float y);
        void criarInimigoGaivota(float x, float y);
        void criarFaseJardim();
    };
}


#endif //FASE1_H
