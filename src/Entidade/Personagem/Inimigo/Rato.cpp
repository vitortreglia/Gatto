#include "Entidade/Personagem/Inimigo/Rato.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Rato::Rato(float x, float y):
            Inimigo(200.0f, {80.0f, 80.0f}, x, y, 2, IDs::IDs::InimigoRato),
            atirouProjetil(false),
            podeAtirar(true),
            tempoAtirar(0.0f),
            tempoAndar(0.0f) {
                corpo.setFillColor(sf::Color::Yellow);
            }

            Rato::~Rato() {}

            bool Rato::getAtirou() {
                return atirouProjetil;
            }

            void Rato::setAtirou(bool at) {
                atirouProjetil = at;
            }

            void Rato::atirar() {
                if (podeAtirar) {
                    podeAtirar = false;
                    setAtirou(true);
                } else {
                    tempoAtirar += tempoFrame;
                    if (tempoAtirar > 3.0f) {
                        tempoAtirar = 0.0f;
                        podeAtirar = true;
                    }
                }
            }

            void Rato::mover() {
                if (tempoAndar < 2.0f) {
                    tempoAndar += tempoFrame;
                    andar(getDireita());
                } else {
                    tempoAndar = 0.0f;
                    andar(!getDireita());
                }
            }

            void Rato::executar() {
                atirar();
                verificaVidas();
                mover();
                desenhar();
                atualizarPos();
            }
        }
    }
}