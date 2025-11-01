#include "Entidade/Personagem/Jogador/Jogador.h"

#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Jogador::Jogador():
        Personagem(1000.0f, sf::Vector2f(100, 100), 100, 1300, 7),
        podePular(true)
        {
            Gerenciador::GerenciadorEvento::setJogador(this);
        }

        Jogador::~Jogador() {}

        void Jogador::executar() {
            atualizarPos();
            pGGrafico->moveCamera(x, y);
            desenhar();
        }

        void Jogador::liberaPulo() {
            podePular = true;
        }


        void Jogador::pular() {
            if (noChao && podePular) {
                velocidade.y = -0.35f;
                estaNoChao(false);
                podePular = false;
            }
        }

        void Jogador::mover() {

        }


    }
}
