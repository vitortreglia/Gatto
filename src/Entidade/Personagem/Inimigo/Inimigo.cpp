#include "Entidade/Personagem/Inimigo/Inimigo.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Jogador* Inimigo::pJog1(nullptr);
            Jogador* Inimigo::pJog2(nullptr);

            Inimigo::Inimigo(int nMaldade, float vel, sf:: Vector2f tam, float px, float py, int vidas) :
            Personagem(vel, tam, px, py, vidas),
            nivelMaldade(nMaldade)
            {}

            Inimigo::~Inimigo() {}

            void Inimigo::setJogadores(Jogador *pJ1, Jogador *pJ2) {
                pJog1 = pJ1;
                if (pJ2)
                    pJog2 = pJ2;
            }

            void Inimigo::verificaVidas() {
                if (numVidas <= 0) {
                    cout << "inimigo morreu" << endl;
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

        }
    }
}
