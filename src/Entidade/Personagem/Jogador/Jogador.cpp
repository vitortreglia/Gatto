#include "Entidade/Personagem/Jogador/Jogador.h"

#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Jogador::Jogador():
        Personagem(1000.0f) {
            Gerenciador::GerenciadorEvento::setJogador(this);
        }

        Jogador::~Jogador() {}
        void Jogador::atualizar() {
            atualizarPos();
            desenhar();
        }

        void Jogador::pular() {
            if (noChao) {
                cout << "pulo" << endl;
                velocidade.y = -0.3f;
                estaNoChao(false);
            }
        }


    }
}
