#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Ente_IDs.h"
#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Gaivota::Gaivota(float x, float y):
            ataque(1, 1.0f),
            Inimigo(0, 120.0f, {80.0f, 50.0f},x, y, 2, IDs::Ente_IDs::InimigoGaivota),
            baseY(y),
            amplitude(10.0f),
            frequencia(6.0f),
            tempo(0.0f),
            possuiPeixe(false),
            estado(nullptr)
            {
                andar(true);

                setEstado(dynamic_cast <EstadoGaivota*>(new EstadoPatrulha(this)));

                corpo.setFillColor(sf::Color::White);
                setVoador(true);

                raioPercepcaoX   = 280.0f;
                raioPercepcaoY = 200.0f;
                raioAtaque       = 400.0f;
                velocidadeRasante = 220.0f;
                velocidadeAtaque  = 380.0f;

            }

            Gaivota::~Gaivota(){}

            void Gaivota::danificar(Jogador *pJ) {
                if (!pJ->getImunidadeDano())
                    nivelMaldade++;
                if (nivelMaldade > 1 && !possuiPeixe && ataque.getAtacando()) {
                    possuiPeixe = pJ->perderPeixe();
                }
                pJ->tomarDano(1);
            }

            void Gaivota::mover() {
                deslocamento.y = std::sin(tempo * frequencia * M_PI) * amplitude;
                atualizarPos();
                tempo += tempoFrame;
                if (tempo > 3.0f) {
                    parar();
                    andar(!direita);
                    tempo = 0.0f;
                }
            }

            sf::RectangleShape* Gaivota::getCorpo() {
                return &corpo;
            }

            bool Gaivota::patrulhar(float dt) {
                /*tempo += dt;
                sf::Vector2f pos = getPosicao();
                pos.x += vMax.x * dt * (float)direcao;
                pos.y = baseY + std::sin(tempo * frequencia) * amplitude;
                setPosicao(pos);
                corpo.setPosition(pos);
                //return false;*/
                mover();

                const sf::Vector2f& posJog = pJog->getPosicao();
                sf::Vector2f posicao = getPosicao();
                float dx = posJog.x - posicao.x;
                float dy = posJog.y - posicao.y;
                float adx = std::fabs(dx);
                float ady = std::fabs(dy);

                bool dentroRasante = (adx < raioPercepcaoX) && (ady < raioPercepcaoY);
                return dentroRasante;
            }

            /*
            void Gaivota::decidirEstado(const sf::Vector2f& posJog) {
                sf::Vector2f pos = getPosicao();
                float dx = posJog.x - pos.x;
                float dy = posJog.y - pos.y;
                float adx = std::fabs(dx);
                float ady = std::fabs(dy);

                bool dentroRasante = (adx < raioPercepcaoX) && (ady < raioPercepcaoY);
                float dist2 = dx*dx + dy*dy;
                bool dentroAtaque = (dist2 < (raioAtaque * raioAtaque));

                if (estado != 2) {
                    if (dentroAtaque) {
                        alvoAtaque = posJog;
                        estado = 2;
                    } else if (dentroRasante) {
                        estado = 1;
                    } else {
                        estado = 0;
                    }
                }
            }

            void Gaivota::mover() {
                const float dt = 0.016f;

                //pJog
                sf::Vector2f posJog;
                pJog ? posJog = pJog->getPosicao() : posJog = sf::Vector2f(getPosicao().x, baseY);

                decidirEstado(posJog);

                if (estado == 0) {
                    patrulhar(dt);
                } else if (estado == 1) {
                    fazerRasante(dt, posJog);
                } else if (estado == 2) {
                    fazerAtaque(dt);
                }

                if (pArma)
                    pArma->executar();
                }*/

            void Gaivota::setEstado(EstadoGaivota *pEstado) {
                if (pEstado) {
                    estado = pEstado;
                }

            }


            void Gaivota::executar() {
                //mover();
                verificaVidas();
                estado->executar(tempoFrame);
            }
        }
    }
}
