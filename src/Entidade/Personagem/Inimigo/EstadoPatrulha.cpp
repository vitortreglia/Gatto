#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            EstadoPatrulha::EstadoPatrulha(Gaivota* pGav): EstadoGaivota(pGav){

            }

            EstadoPatrulha::~EstadoPatrulha() {

            }

            void EstadoPatrulha::executar(float dt) {
                if (pGaivota) {
                    //pGaivota->patrulhar(dt);

                    if (pGaivota->patrulhar(dt)) {
                        pGaivota->setEstado(dynamic_cast<EstadoGaivota*>(new EstadoRasante (pGaivota)));
                    }
                }
            }

        }
    }
}
