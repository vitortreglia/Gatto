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
        numVidas(vidas),
        sofrendoDano(false),
        tempoDano(0.0f),
        deslocamento({0.0f, 0.0f}),
        voador(false)
        {
            corpo.setFillColor(sf::Color::Red);
        }

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

        sf::Vector2f Personagem::getDeslocamento() {
            return deslocamento;
        }

        void Personagem::setDeslocamento(sf::Vector2f desl) {
            deslocamento = desl;
        }

        void Personagem::calculaVelocidade() {
            if (!sofrendoDano) {
                if (andando) {
                    direita ? deslocamento.x = (vMax.x * tempoFrame) : deslocamento.x = -(vMax.x * tempoFrame);
                } else {
                    deslocamento.x = 0.0f;
                }
            }
            if (!voador) {
                deslocamento.y += gravidade * tempoFrame;
                if (deslocamento.y > vMax.y * tempoFrame)
                    deslocamento.y = vMax.y * tempoFrame;
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
                sofrendoDano = true;
                numVidas -= dano;
                cout << "dano em " << (int)ID << endl;
            }
        }

        void Personagem::setVoador(bool voador) {
            this->voador = voador;
        }


    }
}