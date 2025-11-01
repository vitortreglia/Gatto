#include "../../../includes/Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        Personagem::Personagem(float vel, sf::Vector2f tam, float px, float py, int vidas):
        Entidade(tam, px, py),
        velocidade(sf::Vector2f(0.0f, 0.0f)),
        vMax(sf::Vector2f(vel, 500.0f)),
        aceleracao(sf::Vector2f(1.0f, 1.0f)),
        direita(true),
        andando(false),
        noChao(false),
        numVidas(vidas),
        vivo(true)
        {
            corpo.setFillColor(sf::Color::Red);
        }

        Personagem::~Personagem() {
            velocidade = sf::Vector2f(0.0f, 0.0f);
            andando = false;
        }

        void Personagem::setVel(sf::Vector2f vel) {
            velocidade = vel;
        }

        sf::Vector2f Personagem::getVel() {
            return velocidade;
        }

        void Personagem::andar(const bool esq) {
            direita = esq;
            andando = true;
        }

        void Personagem::parar() {
            andando = false;
        }

        void Personagem::calculaVelocidade() {
            if (andando) {
                direita ? velocidade.x += (aceleracao.x * tempoFrame) : velocidade.x += -(aceleracao.x * tempoFrame);

            } else {
                velocidade.x = 0.0f;
            }
            if (velocidade.x > vMax.x * tempoFrame) {
                velocidade.x = vMax.x * tempoFrame;
            } else if (velocidade.x < -(vMax.x * tempoFrame)) {
                velocidade.x = -(vMax.x * tempoFrame);
            }
            velocidade.y += aceleracao.y * tempoFrame;
            //velocidade.y = vMax.y * dt;
        }

        void Personagem::atualizarPos() {
            setPosicao(sf::Vector2f(getPosicao().x + velocidade.x, getPosicao().y + velocidade.y));
            calculaVelocidade();
        }

        void Personagem::atualizarPos(sf::Vector2f pos) {
            setPosicao(sf::Vector2f(pos.x, pos.y));
        }

        void Personagem::estaNoChao(bool c) {
            noChao = c;
        }


        void Personagem::colisao(sf::Vector2f colisao) {
            if (colisao.y < 0.0f) {
                estaNoChao(true);
                if (colisao.x != 0.0f) {
                    float tg;
                    tg = colisao.x / colisao.y;
                    if (tg >= -1 && tg <= 1 && velocidade.y > 0.0f) {
                        velocidade.y = 0.0f;
                    }
                } else {
                    velocidade.y = 0.0f;
                }
                if (colisao.y < -0.5f)
                    numVidas = 0;
            } else if (colisao.y > 0.0f) {
                velocidade.y = velocidade.y * -1;
            } else if (colisao.x > 0.01f || colisao.x < -0.01f) {
                velocidade.x = 0.0f;
            }
            colisao.x += getPosicao().x;
            colisao.y += getPosicao().y;
            atualizarPos(colisao);
        }


    }
}