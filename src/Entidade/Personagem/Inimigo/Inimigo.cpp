#include "Entidade/Personagem/Inimigo/Inimigo.h"

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Jogador* Inimigo::pJog1(nullptr);
            Jogador* Inimigo::pJog2(nullptr);

            Inimigo::Inimigo(int nMaldade, float vel, sf:: Vector2f tam, float px, float py, int vidas) :
            Personagem(vel, tam, px, py, vidas),
            nivelMaldade(nMaldade),
            pUltimoAtacante(nullptr)
            {}

            Inimigo::~Inimigo() {}

            void Inimigo::setJogadores(Jogador *pJ1, Jogador *pJ2) {
                if (pJ1)
                    pJog1 = pJ1;
                if (pJ2)
                    pJog2 = pJ2;
            }

            void Inimigo::setUltimoAtacante(Jogador *pJ) {
                if (pJ)
                    pUltimoAtacante = pJ;
            }

            void Inimigo::verificaVidas() {
                if (numVidas <= 0) {
                    cout << "inimigo morreu" << endl;
                    pUltimoAtacante->pontuar(nivelMaldade * 100 + 100);
                    setAtivo(false);
                } else if (sofrendoDano) {
                    corpo.setFillColor(sf::Color::Red);
                    tempoDano += tempoFrame;
                    if (tempoDano > 0.5f) {
                        sofrendoDano = false;
                        tempoDano = 0.0f;
                        corpo.setFillColor(sf::Color::White);
                    }
                }
            }

            void Inimigo::lerDataBuffer() {
                int idJ;
                Personagem::lerDataBuffer();
                entrada >> nivelMaldade >> idJ;
                if (idJ != 0) {
                    if (pJog1->getId() == idJ)
                        pUltimoAtacante = pJog1;
                    else if (pJog2->getId() == idJ)
                        pUltimoAtacante = pJog2;
                }
            }

            void Inimigo::salvarDataBuffer() {
                Personagem::salvarDataBuffer();
                buffer << nivelMaldade << ' ';
                if (pUltimoAtacante)
                    buffer << pUltimoAtacante->getId() << ' ';
                else
                    buffer << 0 << ' ';
            }

        }
    }
}
