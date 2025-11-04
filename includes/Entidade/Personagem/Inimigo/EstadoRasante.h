
#ifndef GATTO_ESTADORASANTE_H
#define GATTO_ESTADORASANTE_H
#include "EstadoGaivota.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class EstadoRasante : public EstadoGaivota {
            private:
                float distX;
                float distY;
                bool distCalculada;
            public:
                EstadoRasante(Gaivota* pGav);
                ~EstadoRasante();
                void executar(float dt);
            };
        }
    }
}

#endif //GATTO_ESTADORASANTE_H