
#ifndef GATTO_ESTADOPATRULHA_H
#define GATTO_ESTADOPATRULHA_H
#include "EstadoGaivota.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class EstadoPatrulha : public EstadoGaivota {
            public:
                EstadoPatrulha(Gaivota* pGav);
                ~EstadoPatrulha();
                void executar(float dt);
            };
        }
    }
}

#endif //GATTO_ESTADOPATRULHA_H