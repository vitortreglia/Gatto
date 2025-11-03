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
        void criarPlataformaMovel(float x, float y);
        void criarPlataformaGiratoria(float x, float y);
        void criarInimigoRato(float x, float y);
        void criarFaseTorre();
    };
}


#endif //FASE1_H
