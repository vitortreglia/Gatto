#include "Entidade/Personagem/Inimigo/Rato.h"

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Rato::Rato(float x, float y):
            Inimigo(0, 150.0f, {80.0f, 80.0f}, x, y, 2, IDs::Ente_IDs::InimigoRato),
            atirouProjetil(false),
            podeAtirar(true),
            tempoAtirar(0.0f),
            tempoAndar(0.0f),
            imgRato("Data/Imagens/Rato.png")
            {
                textura.setTextura(imgRato);
                setTextura(&textura);
                andar(getDireita());
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

            void Rato::danificar(Jogador *pJ) {
                nivelMaldade++;
                pJ->tomarDano(nivelMaldade);
            }

            void Rato::tomarDano(int dano) {
                if (!sofrendoDano) {
                    sofrendoDano = true;
                    deslocamento.y = -10.0f;
                    deslocamento.x = 0.0f;
                    tempoAndar -= tempoFrame;
                    numVidas -= dano;
                }
            }

            void Rato::mover() {
                if (getDireita()) {
                    atualizarAnimacao({80, 0, -80, 80});
                } else {
                    atualizarAnimacao({0, 0, 80, 80});
                }
                if (!sofrendoDano) {
                    if (tempoAndar < 2.0f && andando) {
                        tempoAndar += tempoFrame;
                    } else {
                        tempoAndar = 0.0f;
                        andar(!getDireita());
                    }
                }
                atualizarPos();
            }

            void Rato::executar() {
                //atirar();
                verificaVidas();
                mover();
            }
        }
    }
}
