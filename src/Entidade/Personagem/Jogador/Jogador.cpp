#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Jogador::Jogador(Itens::Arma* pG):
        Personagem(600.0f, sf::Vector2f(100, 100), 100, 1700, 7, IDs::IDs::Jogador1),
        podePular(true),
        pGarra(pG),
        peixes(0),
        interface("oiii", 30, 20, 50)
        {
            Gerenciador::GerenciadorEvento::setJogador(this);
            pG->setPersonagem(this);
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

        void Jogador::atacar() {
            if (!pGarra->getAtacando())
                pGarra->setAtacando(true);
        }

        void Jogador::colisao(sf::Vector2f colisao, Entidade *pEntidade) {
            if (pEntidade->getId() == IDs::IDs::ItemPeixe && peixes < 3) {
                pEntidade->setAtivo(false);
                peixes++;
            }
            if (colisao.y < 0.0f) {
                estaNoChao(true);
                if (pEntidade->getId() >= IDs::IDs::InimigoGaivota && pEntidade->getId() <= IDs::IDs::Projetil) {
                    pEntidade->colisao({colisao.x * -1, colisao.y * -1}, this);
                    pular(1);
                } else {
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
                        tomarDano(100);
                }
            } else if (colisao.y > 0.0f) {
                if (pEntidade->getId() >= IDs::IDs::InimigoGaivota && pEntidade->getId() <= IDs::IDs::Projetil && !sofrendoDano)
                    tomarDano(1);
                deslocamento.y = deslocamento.y * -1;
            } else if (colisao.x != 0.0f) {
                if (pEntidade->getId() >= IDs::IDs::InimigoGaivota && pEntidade->getId() <= IDs::IDs::Projetil && !sofrendoDano) {
                    tomarDano(1);
                    deslocamento.x = deslocamento.x * -1;
                    pular(0.5);
                } else {
                    deslocamento.x = 0.0f;
                }
            }
            colisao.x += getPosicao().x;
            colisao.y += getPosicao().y;
            atualizarPos(colisao);
        }


        void Jogador::verificaVidas() {
            if (numVidas <= 0) {
                cout << "morreu " << endl;
                setAtivo(false);
            } else if (sofrendoDano) {
                tempoDano += tempoFrame;
                if (tempoDano > 0.5f) {
                    sofrendoDano = false;
                    tempoDano = 0.0f;
                }
            }
        }

        void Jogador::mover() {
            if (!pGarra->getAtacando())
                atualizarPos();
        }

        void Jogador::executar() {
            verificaVidas();
            pGGrafico->moveCamera(x, y);
            desenhar();
            mover();
            interface.setTexto(std::to_string(numVidas) + " vidas | " + std::to_string(peixes) + " peixes");
            interface.executar();
        }

    }
}
