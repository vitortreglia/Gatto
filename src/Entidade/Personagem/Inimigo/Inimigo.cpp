#include "Entidade/Personagem/Inimigo/Inimigo.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {

            Inimigo::Inimigo(int nMaldade, float vel, sf:: Vector2f tam, float px, float py, int vidas, IDs::Ente_IDs id) :
            Personagem(vel, tam, px, py, vidas, id),
            nivelMaldade(nMaldade)
            {}

            Inimigo::~Inimigo() {}


            void Inimigo::verificaDistanciaJogador(sf::Vector2f distSeguir, sf::Vector2f distAtacar) {
                //sf::Vector2f cJ = pJog->getPosicao();
                /*if (cJ.x - this->getPosicao().x < distSeguir.x) {
                    //if (cJ.y - this->getPosicao().y < distSeguir.y || this->getPosicao().y)
                }*/
            }

            void Inimigo::verificaVidas() {
                if (numVidas <= 0) {
                    cout << "inimigo morreu" << endl;
                    setAtivo(false);
                } else if (sofrendoDano) {
                    tempoDano += tempoFrame;
                    if (tempoDano > 0.5f) {
                        sofrendoDano = false;
                        tempoDano = 0.0f;
                    }
                }
            }

            void Inimigo::executar() {
                verificaVidas();
                atualizarPos();
            }

        }
    }
}
