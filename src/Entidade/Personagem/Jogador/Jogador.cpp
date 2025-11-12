#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Gerenciador::GerenciadorEvento* Jogador::pGEvento(nullptr);

        Jogador::Jogador():
        Personagem(600.0f, sf::Vector2f(100, 100), 1600, 4500, 7, IDs::Ente_IDs::Jogador1),
        ataque(1, 0.1f),
        podePular(true),
        peixes(0),
        deslocAtaque(0.0f),
        interface("oiii", 30, 20, 50),
        imunidadeDano(false)
        {}

        Jogador::~Jogador() {}

        void Jogador::setGerenciadorEvento() {
            pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        }

        void Jogador::observarEntrada() {
            pGEvento->inscrever(this);
        }

        void Jogador::ignorarEntrada() {
            pGEvento->desinscrever(this);
        }

        void Jogador::liberaPulo() {
            podePular = true;
        }

        void Jogador::pular(float multiplicador) {
            if (noChao && podePular) {
                deslocamento.y = -30.0f * multiplicador;
                estaNoChao(false);
                podePular = false;
            }
        }

        void Jogador::coletarPeixe(Itens::Peixe *pPeixe) {
            pPeixe->setAtivo(false);
            peixes++;
        }

        bool Jogador::perderPeixe() {
            if (peixes > 0) {
                peixes--;
                return true;
            }
            return false;
        }

        bool Jogador::getImunidadeDano() {
            return imunidadeDano;
        }

        void Jogador::colidir(Inimigo::Inimigo* pInimigo, sf::Vector2f colisao) {
            if (colisao.y < 0.0f) {
                pular(1.0f);
                pInimigo->tomarDano(1);
            } else if (ataque.getAtacando() || deslocAtaque != 0.0f) {
                if (getDireita()) {
                    if (colisao.x < 0.0f) {
                        pInimigo->tomarDano(ataque.getDano());
                    } else {
                        pInimigo->danificar(this);
                    }
                } else if (colisao.x > 0.0f) {
                        pInimigo->tomarDano(ataque.getDano());
                } else {
                    pInimigo->danificar(this);
                }
            } else {
                if (colisao.x < 0.0f) {
                    deslocamento.x = -5.0f;
                } else {
                    deslocamento.x = 5.0f;
                }
                pular(0.5f);
                pInimigo->danificar(this);
            }
        }

        void Jogador::colidir(sf::Vector2f colisao) {
            if (colisao.x < 0.0f) {
                deslocamento.x = -5.0f;
            } else {
                deslocamento.x = 5.0f;
            }
            pular(0.5f);
            tomarDano(1);
        }

        void Jogador::tomarDano(int dano) {
            if (!imunidadeDano) {
                sofrendoDano = true;
                imunidadeDano = true;
                numVidas -= dano;
                cout << "dano em " << (int)ID << endl;
            }
        }

        void Jogador::verificaVidas() {
            if (numVidas <= 0) {
                cout << "morreu " << endl;
                setAtivo(false);
            } else if (imunidadeDano) {
                tempoDano += tempoFrame;
                if (tempoDano > 0.5f) {
                    sofrendoDano = false;
                }
                if (tempoDano > 1.0f) {
                    deslocamento.x = 0.0f;
                    tempoDano = 0.0f;
                    imunidadeDano = false;
                }
            }

        }

        void Jogador::mover() {
            if (ataque.getAtacando()) {
                if (getDireita()) {
                    deslocamento.x = 15.0;
                } else {
                    deslocamento.x = -15.0;
                }
                deslocAtaque += deslocamento.x;
                ataque.ataque(tempoFrame);
            } else if (deslocAtaque != 0 && !sofrendoDano) {
                deslocamento.x = deslocAtaque * -1;
                deslocAtaque = 0.0f;
                ataque.liberaAtaque();
            }
            atualizarPos();
        }

        void Jogador::executar() {
            verificaVidas();
            pGGrafico->moveCamera(getPosicao());
            mover();
            if (peixes < 3)
                interface.setTexto(std::to_string(numVidas) + " vidas | " + std::to_string(peixes) + " peixes");
            else
                interface.setTexto("Venceu");
            interface.executar();
            //cout << deslocamento.x << endl;
        }

        void Jogador::tratarEventos() {
            set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
            set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();
            if (teclasPressionadas.count(sf::Keyboard::A)) {
                andar(false);
            } else if (teclasPressionadas.count(sf::Keyboard::D)) {
                andar(true);
            } else {
                parar();
            }
            if (teclasPressionadas.count(sf::Keyboard::W)) {
                pular(1.0f);
            }
            if (teclasSoltas.count(sf::Keyboard::W)) {
                liberaPulo();
            }
            if (teclasSoltas.count(sf::Keyboard::Space)) {
                ataque.atacar();
            }
        }

        void Jogador::notificar() {
            tratarEventos();
        }
    }
}
