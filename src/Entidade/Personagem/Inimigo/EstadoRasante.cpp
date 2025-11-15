#include "Entidade/Personagem/Inimigo/EstadoRasante.h"

#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            EstadoRasante::EstadoRasante(Gaivota* pGav, Jogador* pJog): EstadoGaivota(pGav) {
                vetorAtaque = pJog->getPosicao() - pGaivota->getPosicao();
                tempo = 0;
                if (vetorAtaque.x > 0) {
                    pGaivota->atualizarAnimacao({80, 0, -80, 50});
                } else {
                    pGaivota->atualizarAnimacao({0, 0, 80, 50});
                }
            }
            
            EstadoRasante::~EstadoRasante() {
                
            }

            void EstadoRasante::executar(float dt) {
                if (pGaivota) {
                    pGaivota->ataque.ataque(dt);
                    tempo += dt;
                    if (tempo <= 1) {
                        pGaivota->atualizarPos({pGaivota->getPosicao().x + vetorAtaque.x * dt, pGaivota->getPosicao().y +vetorAtaque.y * dt});

                    }else {
                        if (vetorAtaque.x < 0) {
                            pGaivota->atualizarAnimacao({80, 0, -80, 50});
                        } else {
                            pGaivota->atualizarAnimacao({0, 0, 80, 50});
                        }
                        pGaivota->atualizarPos({pGaivota->getPosicao().x - vetorAtaque.x * dt, pGaivota->getPosicao().y - vetorAtaque.y * dt});
                    }

                    if (tempo >= 2) {
                        pGaivota->ataque.liberaAtaque();
                        pGaivota->setEstado(dynamic_cast<EstadoGaivota*>(new EstadoPatrulha (pGaivota)));
                    }
                }

            }

        }
    }
}
