#include "../../../includes/Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        Personagem::Personagem(sf::Vector2f vel):
        Entidade(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f)),
        velocidade(vel),
        esquerda(true),
        andando(false),
        dt(0.0f)
        {}

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

        void Personagem::atualizarPos() {
            if (andando) {
                dt = pGGrafico->getTempo();
                sf::Vector2f ds;
                esquerda ? ds.x = velocidade.x * dt : ds.x = velocidade.x * dt * -1;
                ds.y = 0.0f;

                setPosicao(sf::Vector2f(pos.x + ds.x, pos.y + ds.y));
            }
        }

    }
}