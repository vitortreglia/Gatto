#include "Entidade/Itens/Projetil.h"

namespace Entidade {
    namespace Itens {
        Projetil::Projetil() :
        Entidade({44.0f, 38.0f}, 0, 0),
        tempoLancamento(0.0f)
        {
            setAtivo(false);
            textura.inserirTextura("base", "Data/Imagens/osso.png");
            textura.setAnimacao("base");
        }

        Projetil::~Projetil() {}

        void Projetil::setDirecao(bool dir) {
            direita = dir;
        }

        void Projetil::mover() {
            tempoLancamento += tempoFrame;
            if (tempoLancamento < 4.0f) {
                if (direita) {
                    setPosicao({getPosicao().x + 300 * tempoFrame, getPosicao().y});
                } else {
                    setPosicao({getPosicao().x - 300 * tempoFrame, getPosicao().y});
                }
            } else {
                setAtivo(false);
            }
        }

        void Projetil::executar() {
            mover();
            desenhar();
        }

        void Projetil::lerDataBuffer() {
            Entidade::lerDataBuffer();
            entrada >> tempoLancamento >> direita;
        }

        void Projetil::carregar(istream &entrada) {
            this->entrada.rdbuf(entrada.rdbuf());
            lerDataBuffer();
        }

        void Projetil::salvarDataBuffer() {
            buffer << "projetil ";
            Entidade::salvarDataBuffer();
            buffer << tempoLancamento << ' ' << direita << endl;
        }

        void Projetil::salvar(ostream &saida) {
            buffer.rdbuf(saida.rdbuf());
            salvarDataBuffer();
        }

    }
}