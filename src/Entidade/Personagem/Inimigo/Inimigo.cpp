#include "Entidade/Personagem/Inimigo/Inimigo.h"

#include "Entidade/Itens/Arma.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Inimigo::Inimigo(float vel, sf:: Vector2f tam, float px, float py, int vidas, IDs::IDs id) :
            Personagem(vel, tam, px, py, vidas, id)
            {}

            Inimigo::~Inimigo() {}

            void Inimigo::colisao(sf::Vector2f colisao, Entidade *pEntidade) {
                if (pEntidade->getId() == IDs::IDs::ArmaGarra) {
                    tomarDano(static_cast<Itens::Arma*>(pEntidade)->getForca());
                    deslocamento.y = -5.0f;
                    deslocamento.x = colisao.x;
                } else if (colisao.y < 0.0f) {
                    estaNoChao(true);
                    if (pEntidade->getId() == IDs::IDs::Jogador1) {
                        pEntidade->colisao({colisao.x * -1, colisao.y * -1}, this);
                    }
                    else {
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
                    if (pEntidade->getId() == IDs::IDs::Jogador1)
                        tomarDano(1);
                    deslocamento.y = deslocamento.y * -1;
                } else if (colisao.x != 0.0f) {
                    deslocamento.x = 0.0f;
                }
                colisao.x += getPosicao().x;
                colisao.y += getPosicao().y;
                atualizarPos(colisao);
            }

            void Inimigo::verificaVidas() {
                if (numVidas <= 0) {
                    cout << "inimigo morreu" << endl;
                    setAtivo(false);
                } else if (sofrendoDano) {
                    tempoDano += tempoFrame;
                    if (tempoDano > 0.3f) {
                        sofrendoDano = false;
                        tempoDano = 0.0f;
                    }
                }
            }

            void Inimigo::mover() {

            }

            void Inimigo::executar() {
                verificaVidas();
                desenhar();
                atualizarPos();
            }

        }
    }
}
