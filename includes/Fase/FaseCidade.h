#ifndef GATTO_FASECIDADE_H
#define GATTO_FASECIDADE_H

#include "Fase.h"

namespace Fase {

    class FaseCidade : public Fase {
    private:
        void criarFaseCidade();
    public:
        FaseCidade();
        ~FaseCidade();

    };
}
#endif //GATTO_FASECIDADE_H