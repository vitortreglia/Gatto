#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Ente_IDs.h"
#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Gaivota::Gaivota(float x, float y):
            Inimigo(1, 120.0f, {80.0f, 50.0f},x, y, 2, IDs::Ente_IDs::InimigoGaivota),
            baseY(y),
            amplitude(30.0f),
            frequencia(5.0f),
            tempo(0.0f)
            {
                andar(true);
                //setPosicao(sf::Vector2f(x, y));
                //baseY = y;

                //setTamanho(sf::Vector2f(80.0f, 50.0f));

                //tempo = 0.0f;
                //amplitude = 30.0;
                //frequencia = 5.0f;
                direcao = 1;

                setEstado(dynamic_cast <EstadoGaivota*>(new EstadoPatrulha(this)));

                //numVidas = 2;
                //vivo = true;
                corpo.setFillColor(sf::Color::White);
                setVoador(true);

                raioPercepcaoX   = 280.0f;
                raioPercepcaoY = 200.0f;
                raioAtaque       = 400.0f;
                velocidadeRasante = 220.0f;
                velocidadeAtaque  = 380.0f;

                //pArma = nullptr;
                possuiPeixe = false;
            }

            Gaivota::~Gaivota(){}

            void Gaivota::danificar(Jogador *pJ) {
                nivelMaldade++;
                pJ->tomarDano(nivelMaldade);
            }

            void Gaivota::mover() {
                deslocamento.y = std::sin(tempo * frequencia) * amplitude;
                atualizarPos();
                tempo += tempoFrame;
                if (tempo > 4.0f) {
                    parar();
                    andar(!direita);
                    tempo = 0.0f;
                }
            }

            //Jogador* Gaivota::getJogador() {
            //    return pJog;
            //}

            sf::RectangleShape* Gaivota::getCorpo() {
                return &corpo;
            }
            bool Gaivota::patrulhar(float dt) {
                tempo += dt;
                sf::Vector2f pos = getPosicao();
                pos.x += vMax.x * dt * (float)direcao;
                pos.y = baseY + std::sin(tempo * frequencia) * amplitude;
                setPosicao(pos);
                corpo.setPosition(pos);
                //return false;

                const sf::Vector2f& posJog = pJog->getPosicao();
                sf::Vector2f posicao = getPosicao();
                float dx = posJog.x - posicao.x;
                float dy = posJog.y - posicao.y;
                float adx = std::fabs(dx);
                float ady = std::fabs(dy);

                bool dentroRasante = (adx < raioPercepcaoX) && (ady < raioPercepcaoY);
                return dentroRasante;
            }

            bool Gaivota::fazerAtaque(float dt) {
                /*sf::Vector2f dir = alvoAtaque - pos;

                float dist = std::sqrt(dir.x*dir.x + dir.y*dir.y);
                if (dist < 8.0f) {

                    estado = 0;
                    if (pArma)
                        pArma->setAtacando(false);
                    //return false;
                }

                dir.x /= dist;
                dir.y /= dist;

                pos.x += dir.x * velocidadeAtaque * dt;
                pos.y += dir.y * velocidadeAtaque * dt;

                setPosicao(pos);
                corpo.setPosition(pos);

                if (pArma && !pArma->getAtacando())
                    pArma->setAtacando(true);*/
                return false;
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
