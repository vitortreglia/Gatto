
#include "Entidade/Personagem/Inimigo/EstadoGaivota.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            EstadoGaivota::EstadoGaivota(Gaivota* pGav) {
                pGaivota = pGav;
            }

            EstadoGaivota::~EstadoGaivota() {

            }
        }
    }
}