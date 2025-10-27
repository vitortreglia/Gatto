#include "../../../includes/Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        Personagem::Personagem(float vel):
        Entidade(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(400.0f, 100.0f)),
        velocidade(sf::Vector2f(0.0f, 0.0f)),
        vMax(sf::Vector2f(vel, 300.0f)),
        aceleracao(sf::Vector2f(300.0f, 2000.0f)),
        esquerda(true),
        andando(false),
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
            esquerda = esq;
            andando = true;
        }

        void Personagem::parar() {
            andando = false;
        }

        void Personagem::calculaVelocidade() {
            if (andando) {
                esquerda ? velocidade.x += (aceleracao.x * dt * dt) / 2 : velocidade.x += -(aceleracao.x * dt * dt) / 2;
            } else {
                velocidade.x = 0.0;
            }
            if (velocidade.x > vMax.x * dt) {
                velocidade.x = vMax.x * dt;
            } else if (velocidade.x < -vMax.x * dt) {
                velocidade.x = -vMax.x * dt;
            }
            velocidade.y += ((aceleracao.y * dt * dt) / 2);
        }

        void Personagem::atualizarPos() {
            dt = pGGrafico->getTempo();
            calculaVelocidade();
            setPosicao(sf::Vector2f(getPosicao().x + velocidade.x, getPosicao().y + velocidade.y));
        }

        void Personagem::colisao(float overlap) {
            velocidade.y = 0.0f - (overlap * dt) / 2;
            atualizarPos();
        }

        void Personagem::desenhar() {
            Entidade::desenhar();
        }

        void Personagem::atualizar() {
            atualizarPos();
            Entidade::atualizar();
        }


    }
}