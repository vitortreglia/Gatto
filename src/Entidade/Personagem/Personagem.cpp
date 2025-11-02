#include "../../../includes/Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        Personagem::Personagem(float vel, sf::Vector2f tam, float px, float py, int vidas, IDs::IDs id):
        Entidade(tam, px, py, id),
        vMax(sf::Vector2f(vel, 1000.0f)),
        gravidade(100.0f),
        direita(true),
        andando(false),
        noChao(false),
        numVidas(vidas)
        {
            corpo.setFillColor(sf::Color::Red);
        }

        Personagem::~Personagem() {
            andando = false;
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
                direita ? deslocamento.x = (vMax.x * tempoFrame) : deslocamento.x = -(vMax.x * tempoFrame);

            } else {
                deslocamento.x = 0.0f;
            }
            deslocamento.y += gravidade * tempoFrame;
            if (deslocamento.y > vMax.y * tempoFrame)
                deslocamento.y = vMax.y * tempoFrame;
            //velocidade.y = vMax.y * dt;
        }

        void Personagem::atualizarPos() {
            //if (noChao)
            //    setPosicao(sf::Vector2f(getPosicao().x + deslocamento.x, getPosicao().y));
            //else

            setPosicao(sf::Vector2f(getPosicao().x + deslocamento.x, getPosicao().y + deslocamento.y));
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
                    if (tg >= -1 && tg <= 1 && deslocamento.y > 0.0f) {
                        deslocamento.y = 0.0f;
                    }
                } else if (deslocamento.y > 0.0f) {
                    deslocamento.y = 0.0f;
                }
                if (colisao.y < -30.0f)
                    numVidas = 0;
            } else if (colisao.y > 0.0f) {
                deslocamento.y = deslocamento.y * -1;
            } else if (colisao.x != 0.0f) {//(colisao.x > 0.02f || colisao.x < -0.02f) {
                deslocamento.x = 0.0f;
            }
            colisao.x += getPosicao().x;
            colisao.y += getPosicao().y;
            atualizarPos(colisao);
        }


    }
}