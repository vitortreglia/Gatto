#include "../../../includes/Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        Personagem::Personagem(float vel):
        Entidade(sf::Vector2f(100.0f, 100.0f), 400.0f, 200.0f),
        velocidade(sf::Vector2f(0.0f, 0.0f)),
        vMax(sf::Vector2f(vel, 1000.0f)),
        aceleracao(sf::Vector2f(2000.0f, 10000.0f)),
        direita(true),
        andando(false),
        noChao(false),
        dt(0.0f),
        deltaS(sf::Vector2f(0.0f, 0.0f)) {
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
                direita ? velocidade.x += (aceleracao.x * dt * dt) / 2 : velocidade.x += -(aceleracao.x * dt * dt) / 2;
            } else {
                velocidade.x = 0.0f;
            }
            if (velocidade.x > vMax.x * dt) {
                velocidade.x = vMax.x * dt;
            } else if (velocidade.x < -vMax.x * dt) {
                velocidade.x = -vMax.x * dt;
            }
            velocidade.y += ((aceleracao.y * dt * dt) / 2);
            //velocidade.y = vMax.y * dt;
        }

        void Personagem::mover() {
            dt = pGGrafico->getTempo();
            //cout << velocidade.x << endl;
            setPosicao(sf::Vector2f(getPosicao().x + velocidade.x, getPosicao().y + velocidade.y));
            calculaVelocidade();
        }

        void Personagem::mover(sf::Vector2f pos) {
            setPosicao(sf::Vector2f(pos.x, pos.y));
        }

        void Personagem::estaNoChao(bool c) {
            noChao = c;
        }


        void Personagem::colisao(sf::Vector2f colisao) {
            cout << colisao.x << " " << colisao.y << endl;
            if (colisao.y != 0.0f) {
                if (colisao.y < 0.0f) {
                    estaNoChao(true);
                }
                if (colisao.x != 0.0f) {
                    float tg;
                    tg = colisao.x / colisao.y;
                    if (tg >= -1 && tg <= 1 && noChao == true && velocidade.y > 0.0f) {
                        velocidade.y = 0.0f;
                    }
                } else {
                    velocidade.y = 0.0f;
                }
            } else if (colisao.x != 0.0f) {
                 velocidade.x = 0.0f;
            }
            colisao.x += getPosicao().x;
            colisao.y += getPosicao().y;
            mover(colisao);
        }


    }
}