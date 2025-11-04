#include "Entidade/Personagem/Inimigo/EstadoRasante.h"

#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            EstadoRasante::EstadoRasante(Gaivota* pGav): EstadoGaivota(pGav) {
                
            }
            
            EstadoRasante::~EstadoRasante() {
                
            }

            void EstadoRasante::executar(float dt) {
                if (pGaivota) {
                    if (pGaivota->fazerAtaque(dt)) {
                        pGaivota->setEstado(dynamic_cast<EstadoGaivota*>(new EstadoPatrulha (pGaivota)));
                    }
                }

            }

        }
    }
}
