#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Ente_IDs.h"
#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Jogador* Gaivota::pJog1(nullptr);
            Jogador* Gaivota::pJog2(nullptr);

            Gaivota::Gaivota(float x, float y):
            ataque(1, 1.0f),
            Inimigo(0, 120.0f, {80.0f, 50.0f},x, y, 2, IDs::Ente_IDs::InimigoGaivota),
            baseY(y),
            amplitude(10.0f),
            frequencia(6.0f),
            tempo(0.0f),
            possuiPeixe(false),
            estado(nullptr),
            imgGaivota("Data/Imagens/Gaivota.png")
            {
                textura.setTextura(imgGaivota);
                setTextura(&textura);
                andar(true);
                setEstado(dynamic_cast <EstadoGaivota*>(new EstadoPatrulha(this)));
                setVoador(true);

                raioPercepcaoX   = 280.0f;
                raioPercepcaoY = 300.0f;
                raioAtaque       = 400.0f;
                velocidadeRasante = 220.0f;
                velocidadeAtaque  = 380.0f;

            }

            Gaivota::~Gaivota(){}

            void Gaivota::setJogadores(Jogador *pJ1, Jogador *pJ2) {
                pJog1 = pJ1;
                if (pJ2)
                    pJog2 = pJ2;
            }

            void Gaivota::danificar(Jogador *pJ) {
                if (!pJ->getImunidadeDano())
                    nivelMaldade++;
                if (nivelMaldade > 1 && !possuiPeixe && ataque.getAtacando()) {
                    possuiPeixe = pJ->perderPeixe();
                }
                pJ->tomarDano(1);
            }

            void Gaivota::mover() {
                if (getDireita()) {
                    atualizarAnimacao({80, 0, -80, 50});
                } else {
                    atualizarAnimacao({0, 0, 80, 50});
                }
                deslocamento.y = std::sin(tempo * frequencia * M_PI) * amplitude;
                atualizarPos();
                tempo += tempoFrame;
                if (tempo > 3.0f) {
                    parar();
                    andar(!direita);
                    tempo = 0.0f;
                }
            }

            Jogador* Gaivota::patrulhar(float dt) {

                mover();

                const sf::Vector2f& posJog = pJog1->getPosicao();
                sf::Vector2f posicao = getPosicao();
                float dx = posJog.x - posicao.x;
                float dy = posJog.y - posicao.y;
                float adx = std::fabs(dx);
                float ady = std::fabs(dy);

                if (adx < raioPercepcaoX && ady < raioPercepcaoY) {
                    return pJog1;
                }

                if (pJog2) {
                    const sf::Vector2f& posJog2 = pJog2->getPosicao();
                    posicao = getPosicao();
                    dx = posJog2.x - posicao.x;
                    dy = posJog2.y - posicao.y;
                    adx = std::fabs(dx);
                    ady = std::fabs(dy);

                    if (adx < raioPercepcaoX && ady < raioPercepcaoY) {
                        return pJog2;
                    }
                }

                return nullptr;
            }


            void Gaivota::setEstado(EstadoGaivota *pEstado) {
                if (pEstado) {
                    estado = pEstado;
                }
            }

            void Gaivota::executar() {
                verificaVidas();
                estado->executar(tempoFrame);
            }
        }
    }
}
