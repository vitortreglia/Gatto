#include "Entidade/Personagem/Inimigo/EstadoRasante.h"

#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            EstadoRasante::EstadoRasante(Gaivota* pGav): EstadoGaivota(pGav) {
                vetorAtaque = Inimigo::getJogador()->getPosicao() - pGaivota->getPosicao();
                tempo = 0;
            }
            
            EstadoRasante::~EstadoRasante() {
                
            }

            void EstadoRasante::executar(float dt) {
                if (pGaivota) {
                    tempo += dt;
                    if (tempo <= 1) {
                        pGaivota->getCorpo()->move(sf::Vector2f{vetorAtaque.x * dt, vetorAtaque.y * dt});

                    }else {
                        pGaivota->getCorpo()->move(sf::Vector2f{vetorAtaque.x * dt, -vetorAtaque.y * dt});
                    }

                    if (tempo >= 2) {
                        pGaivota->setEstado(dynamic_cast<EstadoGaivota*>(new EstadoPatrulha (pGaivota)));
                    }
                }

            }

        }
    }
}
