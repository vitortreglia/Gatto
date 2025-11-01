#include "Entidade/Obstaculo/PlataformaMovel.h"

namespace Entidade {
    namespace Obstaculo {
        PlataformaMovel::PlataformaMovel(sf::Vector2f tam, float x, float y, float totalMovimento):
        Obstaculo(false, tam, x, y),
        movimentoMax(totalMovimento),
        tempoMax(4.0f),
        somaTempo(0.0f),
        direcao(false)
        {}

        PlataformaMovel::~PlataformaMovel() {}

        void PlataformaMovel::mover() {
            float ds = 300 * tempoFrame;
            somaMovimento += ds;
            if (!direcao)
                ds = ds * -1;
            if (somaMovimento < movimentoMax)
                setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + ds));
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