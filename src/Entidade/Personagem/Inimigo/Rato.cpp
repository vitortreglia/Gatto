#include "Entidade/Personagem/Inimigo/Rato.h"

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Rato::Rato(float x, float y):
            Inimigo(1, 150.0f, {80.0f, 80.0f}, x, y, 2),
            tempoAndar(0.0f)
            {
                textura.inserirTextura("andando", "Data/Imagens/Rato/andando.png");
                textura.inserirTextura("dano", "Data/Imagens/Rato/dano.png");
                andar(getDireita());
            }

            Rato::~Rato() {}

            void Rato::danificar(Jogador *pJ) {
                pJ->tomarDano(nivelMaldade);
                nivelMaldade++;
            }

            void Rato::tomarDano(int dano) {
                if (!sofrendoDano) {
                    deslocamento.y = -10.0f;
                    deslocamento.x = 0.0f;
                    tempoAndar -= tempoFrame;
                    Personagem::tomarDano(dano);
                }
            }

            void Rato::mover() {
                if (!sofrendoDano) {
                    textura.setAnimacao("andando");
                    if (tempoAndar < 2.0f && andando) {
                        tempoAndar += tempoFrame;
                    } else {
                        tempoAndar = 0.0f;
                        andar(!getDireita());
                    }
                }
                atualizarPos();
            }

            void Rato::executar() {
                textura.animar(getDireita());
                verificaVidas();
                mover();
            }

            void Rato::lerDataBuffer() {
                Inimigo::lerDataBuffer();
                entrada >> tempoAndar;
            }

            void Rato::carregar(istream &entrada) {
                this->entrada.rdbuf(entrada.rdbuf());
                lerDataBuffer();
            }

            void Rato::salvarDataBuffer() {
                buffer << "rato ";
                Inimigo::salvarDataBuffer();
                buffer << tempoAndar << endl;
            }

            void Rato::salvar(ostream &saida) {
                buffer.rdbuf(saida.rdbuf());
                salvarDataBuffer();
            }

        }
    }
}
