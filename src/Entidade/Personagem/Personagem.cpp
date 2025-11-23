#include "Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        Personagem::Personagem(float vel, sf::Vector2f tam, float px, float py, int vidas):
        Entidade(tam, px, py),
        vMax(vel),
        direita(true),
        andando(false),
        noChao(false),
        numVidas(vidas),
        sofrendoDano(false),
        tempoDano(0.0f)
        {}

        Personagem::~Personagem() {
            andando = false;
        }

        void Personagem::andar(const bool dir) {
            direita = dir;
            andando = true;
        }

        void Personagem::parar() {
            andando = false;
        }

        const bool Personagem::getDireita() const {
            return direita;
        }

        void Personagem::calculaVelocidade() {
            if (!sofrendoDano) {
                if (andando) {
                    direita ? deslocamento.x = (vMax * tempoFrame) : deslocamento.x = -(vMax * tempoFrame);
                } else {
                    deslocamento.x = 0.0f;
                }
            }
            deslocamento.y += gravidade * tempoFrame;
            if (deslocamento.y > 1000 * tempoFrame)
                deslocamento.y = 1000 * tempoFrame;
            if (voador) {
                balancearGravidade();
            }
        }

        void Personagem::atualizarPos() {
            setPosicao(sf::Vector2f(getPosicao().x + deslocamento.x, getPosicao().y + deslocamento.y));
            calculaVelocidade();
            if (getPosicao().y > pGGrafico->getLimitesCamera().height) {
                tomarDano(100);
            }
        }

        void Personagem::atualizarPos(sf::Vector2f pos) {
            setPosicao(sf::Vector2f(pos.x, pos.y));
        }

        void Personagem::estaNoChao(bool c) {
            noChao = c;
        }

        void Personagem::tomarDano(int dano) {
            if (!sofrendoDano) {
                textura.setAnimacao("dano");
                sofrendoDano = true;
                numVidas -= dano;
            }
        }

        void Personagem::lerDataBuffer() {
            Entidade::lerDataBuffer();
            entrada >> numVidas >> deslocamento.x >> deslocamento.y >> direita >> andando >> noChao >> sofrendoDano
            >> tempoDano >> voador;
        }

        void Personagem::salvarDataBuffer() {
            Entidade::salvarDataBuffer();
            buffer << numVidas << ' ' << deslocamento.x << ' ' << deslocamento.y << ' ' << direita << ' ' << andando
            << ' ' << noChao << ' ' << sofrendoDano << ' ' << tempoDano << ' ' << voador << ' ';
        }

    }
}