#include "Entidade/Itens/Peixe.h"

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Entidade {
    namespace Itens {
        Peixe::Peixe(float x, float y):
        Entidade({50, 50}, x, y),
        movimento(60),
        sentido(true) {
            setVoador(true);
            textura.inserirTextura("base", "Data/Imagens/peixe.png");
            textura.setAnimacao("base");
        }

        Peixe::~Peixe() {}

        void Peixe::mover() {
            movimento -= 1;
            if (sentido) {
                setPosicao({getPosicao().x, getPosicao().y - 1});
            } else {
                setPosicao({getPosicao().x, getPosicao().y + 1});
            }
            if (movimento == 1) {
                movimento = 60;
                sentido = !sentido;
            }
        }

        void Peixe::executar() {
            textura.animar(false);
            calculaVelocidade();
            mover();
        }

        void Peixe::lerDataBuffer() {
            Entidade::lerDataBuffer();
            entrada >> movimento >> sentido;
        }

        void Peixe::carregar(istream &entrada) {
            this->entrada.rdbuf(entrada.rdbuf());
            lerDataBuffer();
        }

        void Peixe::salvarDataBuffer() {
            buffer << "peixe ";
            Entidade::salvarDataBuffer();
            buffer << movimento << ' ' << sentido << endl;
        }

        void Peixe::salvar(ostream &saida) {
            buffer.rdbuf(saida.rdbuf());
            salvarDataBuffer();
        }

    }
}
