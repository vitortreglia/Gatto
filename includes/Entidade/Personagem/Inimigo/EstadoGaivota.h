#ifndef GATTO_ESTADOGAIVOTA_H
#define GATTO_ESTADOGAIVOTA_H
//#include "Gaivota.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Gaivota;
            class EstadoGaivota {
                protected:
                    Gaivota* pGaivota;
                public:
                    EstadoGaivota(Gaivota* pGav);
                    ~EstadoGaivota();
                    virtual void executar(float dt)=0;
            };
        }
    }
}

#endif //GATTO_ESTADOGAIVOTA_H