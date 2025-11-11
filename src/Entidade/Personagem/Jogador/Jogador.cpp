#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Jogador::Jogador():
        Personagem(600.0f, sf::Vector2f(100, 100), 1600, 4500, 7, IDs::Ente_IDs::Jogador1),
        Ataque(1),
        podePular(true),
        peixes(0),
        deslocAtaque(0.0f),
        interface("oiii", 30, 20, 50)
        {
            Gerenciador::GerenciadorEvento::setJogador(this);
        }

        Jogador::~Jogador() {}

        void Jogador::liberaPulo() {
            podePular = true;
        }

        void Jogador::pular(float multiplicador) {
            if (noChao && podePular) {
                deslocamento.y = -30.0f * multiplicador;
                estaNoChao(false);
                podePular = false;
            }
        }

        void Jogador::coletarPeixe(Itens::Peixe *pPeixe) {
            pPeixe->setAtivo(false);
            peixes++;
        }

        void Jogador::colidir(Inimigo::Inimigo* pInimigo, sf::Vector2f colisao) {
            if (colisao.y < 0.0f) {
                pular(1.0f);
                pInimigo->tomarDano(1);
            } else if (getAtacando() || deslocAtaque != 0.0f) {
                if (getDireita()) {
                    if (colisao.x < 0.0f) {
                        pInimigo->tomarDano(getDano());
                    } else {
                        pInimigo->danificar(this);
                    }
                } else if (colisao.x > 0.0f) {
                        pInimigo->tomarDano(getDano());
                } else {
                    pInimigo->danificar(this);
                }
            } else {
                if (colisao.x < 0.0f) {
                    deslocamento.x = -5.0f;
                } else {
                    deslocamento.x = 5.0f;
                }
                pular(0.5f);
                pInimigo->danificar(this);
            }
        }

        void Jogador::colidir(sf::Vector2f colisao) {
            if (colisao.x < 0.0f) {
                deslocamento.x = -5.0f;
            } else {
                deslocamento.x = 5.0f;
            }
            pular(0.5f);
            tomarDano(1);
        }


        void Jogador::verificaVidas() {
            if (numVidas <= 0) {
                cout << "morreu " << endl;
                setAtivo(false);
            } else if (sofrendoDano) {
                tempoDano += tempoFrame;
                if (tempoDano > 0.5f) {
                    sofrendoDano = false;
                    deslocamento.x = 0.0f;
                    tempoDano = 0.0f;
                }
            }
        }

        void Jogador::mover() {
            if (getAtacando()) {
                if (getDireita()) {
                    deslocamento.x = 10.0;
                } else {
                    deslocamento.x = -10.0;
                }
                deslocAtaque += deslocamento.x;
                ataque(tempoFrame);
            } else if (deslocAtaque != 0) {
                deslocamento.x = deslocAtaque * -1;
                deslocAtaque = 0.0f;
            }
            atualizarPos();
        }

        void Jogador::executar() {
            verificaVidas();
            pGGrafico->moveCamera(getPosicao());
            mover();
            if (peixes < 3)
                interface.setTexto(std::to_string(numVidas) + " vidas | " + std::to_string(peixes) + " peixes");
            else
                interface.setTexto("Venceu");
            interface.executar();
        }

    }
}
