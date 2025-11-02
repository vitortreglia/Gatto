#include "Entidade/Personagem/Jogador/Jogador.h"

#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Jogador::Jogador():
        Personagem(600.0f, sf::Vector2f(100, 100), 100, 1300, 7),
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
<<<<<<< Updated upstream
                cout << "pulo" << endl;
                deslocamento.y = -30.0f;
=======
                velocidade.y = -0.40f;
>>>>>>> Stashed changes
                estaNoChao(false);
                podePular = false;
            }
        }

        void Jogador::verificaVidas() {
            if (numVidas <= 0) {
                cout << "morreu " << endl;
                vivo = false;
            }
        }


        void Jogador::mover() {

        }

        void Jogador::executar() {
            verificaVidas();
            pGGrafico->moveCamera(x, y);
            desenhar();
            atualizarPos();
        }

    }
}
