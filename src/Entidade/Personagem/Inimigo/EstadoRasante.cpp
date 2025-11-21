#include "Entidade/Personagem/Inimigo/EstadoRasante.h"

#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            EstadoRasante::EstadoRasante(Gaivota* pGav, Jogador* pJog): EstadoGaivota(pGav) {
                if (pGav && pJog)
                    vetorAtaque = pJog->getPosicao() - pGaivota->getPosicao();
                tempo = 0;
            }
            
            EstadoRasante::~EstadoRasante() {
                
            }

            float EstadoRasante::getTempo() {
                return tempo;
            }

            sf::Vector2f EstadoRasante::getVetorAtaque() {
                return vetorAtaque;
            }

            void EstadoRasante::setTempo(float t) {
                tempo = t;
            }

            void EstadoRasante::setVetorAtaque(sf::Vector2f VA) {
                vetorAtaque = VA;
            }

            void EstadoRasante::executar(float dt) {
                if (pGaivota) {
                    pGaivota->ataque.ataque(dt);
                    tempo += dt;
                    if (tempo <= 1) {
                        pGaivota->atualizarPos({pGaivota->getPosicao().x + vetorAtaque.x * dt, pGaivota->getPosicao().y +vetorAtaque.y * dt});

                    }else {
                        pGaivota->atualizarPos({pGaivota->getPosicao().x - vetorAtaque.x * dt, pGaivota->getPosicao().y - vetorAtaque.y * dt});
                    }

                    if (tempo >= 2) {
                        pGaivota->ataque.liberaAtaque();
                        vetorAtaque = {0, 0};
                        tempo = 0;
                        pGaivota->setEstado(dynamic_cast<EstadoGaivota*>(new EstadoPatrulha (pGaivota)));
                    }
                }

            }

        }
    }
}
