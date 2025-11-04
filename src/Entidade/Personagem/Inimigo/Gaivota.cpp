#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Entidade/Itens/Arma.h"
#include "Entidade/Itens/ArmaInimigo.h"
#include "IDs.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Gaivota::Gaivota(float x, float y):
            Inimigo(0, {80, 50}, x, y, 2, IDs::IDs::InimigoGaivota)
            {
                setPosicao(sf::Vector2f(x, y));
                baseY = y;

                setTamanho(sf::Vector2f(80.0f, 50.0f));

                tempo = 0.0f;
                amplitude = 30.0f;
                velocidadeHorizontal = 120.0f;
                frequencia = 5.0f;
                direcao = 1;

                numVidas = 2;
                vivo = true;
                corpo.setFillColor(sf::Color::White);
                //setVoador(true);
                estado = 0;

                raioPercepcaoX   = 280.0f;
                raioPercepcaoY = 80.0f;
                raioAtaque       = 120.0f;
                velocidadeRasante = 220.0f;
                velocidadeAtaque  = 380.0f;

                pArma = nullptr;
                possuiPeixe = false;
            }

            Gaivota::~Gaivota(){}

            void Gaivota::verificaVidas() {
                if (numVidas <= 0)
                    vivo = false;
            }

            void Gaivota::virarPara(const sf::Vector2f& posJog) {
                float dx = posJog.x - getPosicao().x;
                if (dx > 0) {
                    direcao = 1;
                    andar(true);
                } else {
                    direcao = -1;
                    andar(false);
                }
            }

            void Gaivota::fazerRasante(float dt, const sf::Vector2f& posJog) {
                virarPara(posJog);
                atualizarPos();

                sf::Vector2f pos = getPosicao();
                float dy = posJog.y - pos.y;
                float passoY = velocidadeRasante * dt;

                if (std::fabs(dy) < passoY)
                    pos.y = posJog.y;
                else
                    pos.y += (dy > 0 ? passoY : -passoY);

                setPosicao(pos);
                corpo.setPosition(pos);
            }

            void Gaivota::patrulhar(float dt) {
                tempo += dt;
                sf::Vector2f pos = getPosicao();
                pos.x += velocidadeHorizontal * dt * (float)direcao;
                pos.y = baseY + std::sin(tempo * frequencia) * amplitude;
                setPosicao(pos);
                corpo.setPosition(pos);
            }

            void Gaivota::fazerAtaque(float dt) {
                sf::Vector2f pos = getPosicao();
                sf::Vector2f dir = alvoAtaque - pos;

                float dist = std::sqrt(dir.x*dir.x + dir.y*dir.y);
                if (dist < 8.0f) {

                    estado = 0;
                    if (pArma)
                        pArma->setAtacando(false);
                    return;
                }

                dir.x /= dist;
                dir.y /= dist;

                pos.x += dir.x * velocidadeAtaque * dt;
                pos.y += dir.y * velocidadeAtaque * dt;

                setPosicao(pos);
                corpo.setPosition(pos);

                if (pArma && !pArma->getAtacando())
                    pArma->setAtacando(true);
            }

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
                }

            void Gaivota::executar() {
                mover();
                verificaVidas();
                desenhar();
                cout << pJog->getPosicao().x << endl;
            }


        }
    }
}