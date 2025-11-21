#include "Entidade/Obstaculo/PlataformaMovel.h"

namespace Entidade {
    namespace Obstaculo {
        PlataformaMovel::PlataformaMovel(float x, float y, bool direcao):
        Obstaculo(false, sf::Vector2f(200, 50), x, y),
        movimentoMax(400),
        tempoMax(4.0f),
        somaTempo(0.0f),
        direcao(direcao),
        somaMovimento(0.0f) {
            corpo.setFillColor(sf::Color::Green);
        }

        PlataformaMovel::~PlataformaMovel() {}

        void PlataformaMovel::mover() {
            float ds = 200 * tempoFrame;
            if (ds > movimentoMax - somaMovimento)
                ds = movimentoMax - somaMovimento;
            if (!direcao)
                ds = ds * -1;
            if (somaMovimento < movimentoMax)
                setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + ds));
            somaMovimento += fabs(ds);
        }


        void PlataformaMovel::obstaculizar(Personagem::Jogador* pJog) {
            pJog->pular(1.0f);
        }

        void PlataformaMovel::executar() {
            somaTempo += tempoFrame;
            if (somaTempo > tempoMax) {
                somaTempo = 0.0f;
                direcao = !direcao;
                somaMovimento = 0.0f;
            }
            mover();
        }

        void PlataformaMovel::lerDataBuffer() {
            Obstaculo::lerDataBuffer();
            entrada >> somaMovimento >> somaTempo >> direcao;
        }

        void PlataformaMovel::carregar(istream &entrada) {
            this->entrada.rdbuf(entrada.rdbuf());
            lerDataBuffer();
        }

        void PlataformaMovel::salvarDataBuffer() {
            buffer << "pmovel ";
            Obstaculo::salvarDataBuffer();
            buffer << somaMovimento << ' ' << somaTempo << ' ' << direcao << endl;
        }

        void PlataformaMovel::salvar(ostream &saida) {
            buffer.rdbuf(saida.rdbuf());
            salvarDataBuffer();
        }

    }
}