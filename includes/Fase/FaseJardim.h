#ifndef FASE1_H
#define FASE1_H
#include "Entidade/Personagem/Inimigos/Gaivota.h"
#include "Fase/Fase.h"


namespace Fase {
    class FaseJardim : public Fase{
    private:
        const int maxInimMedios;
        const int maxInimFaceis;
    public:
        FaseJardim();
        ~FaseJardim();
    private:
        void criarPlataformaMovel(float x, float y);
        void criarPlataformaGiratoria(float x, float y);
        void criarGaivota(float x, float y);
        void criarFaseJardim();
    };
}


#endif //FASE1_H
