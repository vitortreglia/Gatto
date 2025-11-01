#include "Entidade/Obstaculo/PlataformaMovel.h"

namespace Entidade {
    namespace Obstaculo {
        PlataformaMovel::PlataformaMovel(float x, float y):
        Obstaculo(false, sf::Vector2f(200, 50), x, y),
        movimentoMax(400),
        tempoMax(4.0f),
        somaTempo(0.0f),
        direcao(false),
        somaMovimento(0.0f)
        {}

        PlataformaMovel::~PlataformaMovel() {}

        void PlataformaMovel::mover() {
            float ds = 300 * tempoFrame;
            if (ds > movimentoMax - somaMovimento)
                ds = movimentoMax - somaMovimento;
            if (!direcao)
                ds = ds * -1;
            if (somaMovimento < movimentoMax)
                setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + ds));
            somaMovimento += fabs(ds);
        }


        void PlataformaMovel::obstaculizar() {
            somaTempo += tempoFrame;
            if (somaTempo > tempoMax) {
                somaTempo = 0.0f;
                direcao = !direcao;
                somaMovimento = 0.0f;
            }
            mover();
        }

        void PlataformaMovel::executar() {
            obstaculizar();
            desenhar();
        }

    }
}