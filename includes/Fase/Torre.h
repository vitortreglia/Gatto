#ifndef FASE1_H
#define FASE1_H
#include "Fase.h"


namespace Fase {
    class Torre : public Fase{
    private:
        const int maxInimMedios;
        const int maxInimFaceis;
    public:
        Torre();
        ~Torre();
    private:
        void criarObstMedios();
    };
}


#endif //FASE1_H
