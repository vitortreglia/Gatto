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
            Inimigo(0, 120.0f, {80.0f, 50.0f},x, y, 2),
            baseY(y),
            amplitude(10.0f),
            frequencia(6.0f),
            tempo(0.0f),
            possuiPeixe(false),
            estado(nullptr),
            imgGaivota("Data/Imagens/Gaivota.png")
            {
                textura.inserirTextura("voando", "Data/Imagens/Gaivota/voando.png");
                textura.inserirTextura("rasante", "Data/Imagens/Gaivota/rasante.png");
                textura.inserirTextura("dano", "Data/Imagens/Gaivota/dano.png");
                andar(true);
                setEstado(dynamic_cast <EstadoGaivota*>(new EstadoPatrulha(this)));
                setVoador(true);

                raioPercepcaoX   = 280.0f;
                raioPercepcaoY = 300.0f;
                raioAtaque       = 400.0f;
                velocidadeRasante = 220.0f;
                velocidadeAtaque  = 380.0f;
                textura.setAnimacao("voando");
            }

            Gaivota::~Gaivota(){}

            void Gaivota::danificar(Jogador *pJ) {
                if (!pJ->getImunidadeDano() && !sofrendoDano) {
                    nivelMaldade++;
                    if (nivelMaldade > 1 && !possuiPeixe && ataque.getAtacando()) {
                        possuiPeixe = pJ->perderPeixe();
                    }
                    pJ->tomarDano(1);
                }
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

            Jogador* Gaivota::patrulhar(float dt) {
                textura.setAnimacao("voando");
                mover();

                const sf::Vector2f& posJog = pJog1->getPosicao();
                sf::Vector2f posicao = getPosicao();
                float dx = posJog.x - posicao.x;
                float dy = posJog.y - posicao.y;
                float adx = std::fabs(dx);
                float ady = std::fabs(dy);

                if (adx < raioPercepcaoX && ady < raioPercepcaoY) {
                    textura.setAnimacao("rasante");
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
                        textura.setAnimacao("rasante");
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
                textura.animar(getDireita());
                verificaVidas();
                estado->executar(tempoFrame);
            }
        }
    }
}
