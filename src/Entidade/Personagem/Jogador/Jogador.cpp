#include "Entidade/Personagem/Jogador/Jogador.h"

#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Jogador::Jogador():
        Personagem(1000.0f) {
            Gerenciador::GerenciadorEvento::setJogador(this);
        }

        Jogador::~Jogador() {}

        void Jogador::executar() {
            atualizarPos();
            desenhar();
        }

        void Jogador::pular() {
            if (noChao) {
                velocidade.y = -0.35f;
                estaNoChao(false);
            }
        }

        void Jogador::mover() {

        }


    }
}
