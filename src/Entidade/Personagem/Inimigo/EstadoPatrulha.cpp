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
                    Jogador* pJog = pGaivota->patrulhar(dt);
                    if (pJog) {
                        pGaivota->ataque.atacar();
                        pGaivota->setEstado(dynamic_cast<EstadoGaivota*>(new EstadoRasante (pGaivota, pJog)));
                    }
                }
            }

        }
    }
}
