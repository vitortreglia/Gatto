#include "Entidade/Personagem/Jogador/Jogador.h"

#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Jogador::Jogador():
        Personagem(600.0f, sf::Vector2f(100, 100), 100, 1300, 7, IDs::IDs::Jogador1),
        podePular(true)
        {
            Gerenciador::GerenciadorEvento::setJogador(this);
        }

        Jogador::~Jogador() {}

        void Jogador::liberaPulo() {
            podePular = true;
        }

        void Jogador::pular() {
            if (noChao && podePular) {
                deslocamento.y = -30.0f;
                estaNoChao(false);
                podePular = false;
            }
        }

        void Jogador::verificaVidas() {
            if (numVidas <= 0) {
                cout << "morreu " << endl;
                ativo = false;
            }
        }


        void Jogador::mover() {
            atualizarPos();
        }

        void Jogador::executar() {
            verificaVidas();
            pGGrafico->moveCamera(x, y);
            desenhar();
            mover();
        }

    }
}
