#ifndef FASECIDADE_H
#define FASECIDADE_H
#include "Fase.h"


namespace Fase {
    class FaseCidade : public Fase {
    protected:
        void criarProjetil(float x, float y, bool direita);
    };
}


#endif //FASECIDADE_H
