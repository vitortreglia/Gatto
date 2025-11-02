#include "Entidade/Personagem/Jogador/Jogador.h"

#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Jogador::Jogador(Itens::Arma* pG):
        Personagem(600.0f, sf::Vector2f(100, 100), 100, 1300, 7, IDs::IDs::Jogador1),
        podePular(true),
        pGarra(pG)
        {
            Gerenciador::GerenciadorEvento::setJogador(this);
            pG->setPersonagem(this);
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

        void Jogador::atacar() {
            if (!pGarra->getAtacando())
                pGarra->setAtacando(true);
        }

        void Jogador::verificaVidas() {
            if (numVidas <= 0) {
                cout << "morreu " << endl;
                ativo = false;
            }
        }

        void Jogador::mover() {
            if (!pGarra->getAtacando())
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
