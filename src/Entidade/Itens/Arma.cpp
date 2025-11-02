#include "Entidade/Itens/Arma.h"

namespace Entidade {
    namespace Itens {
        Arma::Arma(IDs::IDs id):
        Entidade({30.0f, 100.0f}, -1000.0f, -1000.0f, id),
        dano(1),
        tempoAtaque(0.0f),
        tMaxAtaque(0.5f) {
            corpo.setFillColor(sf::Color::White);
        }

        Arma::~Arma() {}

        void Arma::setPersonagem(Personagem::Personagem *pPersonagem) {
            this->pPersonagem = pPersonagem;
        }

        Personagem::Personagem* Arma::getPersonagem() {
            return pPersonagem;
        }

        void Arma::setAtacando(bool atk) {
            atacando = atk;
        }

        bool Arma::getAtacando() {
            return atacando;
        }

        void Arma::ataque() {
            if (pPersonagem->getDireita())
                setPosicao({pPersonagem->getPosicao().x + pPersonagem->getTamanho().x, pPersonagem->getPosicao().y});
            else
                setPosicao({pPersonagem->getPosicao().x - getTamanho().x, pPersonagem->getPosicao().y});
        }

        void Arma::atacar() {
            desenhar();
            pPersonagem->parar();
            if (tempoAtaque == 0.0f) {
                ataque();
            }
            tempoAtaque += tempoFrame;
            if (tempoAtaque > tMaxAtaque) {
                setAtacando(false);
                tempoAtaque = 0.0f;
                setPosicao({-1000.0f, -1000.0f});
            }
        }

        void Arma::colisao(sf::Vector2f colisao) {

        }

        void Arma::executar() {
            if (atacando)
                atacar();
        }

    }
}