#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Gerenciador::GerenciadorEvento* Jogador::pGEvento(nullptr);

        Jogador::Jogador(int nJog):
        Personagem(600.0f, sf::Vector2f(100, 100), 1600, 4500, 7, nJog == 1 ? IDs::Ente_IDs::Jogador1 : IDs::Ente_IDs::Jogador2),
        numJog(nJog),
        vencedor(false),
        ataque(1, 0.1f),
        podePular(true),
        peixes(0),
        deslocAtaque(0.0f),
        interface("oiii", 30, 20, 50),
        imunidadeDano(false),
        imgGato1("Data/Imagens/Gato_01.png"),
        imgGato2("Data/Imagens/Gato_02.png")
        {
            if (numJog == 2) {
                textura.setTextura(imgGato2);
                interface.setPosicao(1020, 50);
            } else {
                textura.setTextura(imgGato1);
            }
            setTextura(&textura);
        }

        Jogador::~Jogador() {
            ignorarEntrada();
        }

        bool Jogador::getVencedor() {
            return vencedor;
        }

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
            if (noChao) {
                deslocamento.y = -30.0f * multiplicador;
                estaNoChao(false);
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
                pGGrafico->setMultiplayer(false);
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
            if (getDireita()) {
                atualizarAnimacao({100, 0, -100, 100});
            } else {
                atualizarAnimacao({0, 0, 100, 100});
            }
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
            pGGrafico->moveCamera(getPosicao(), numJog);
            mover();
            if (peixes < 3)
                interface.setTexto(std::to_string(numVidas) + " vidas | " + std::to_string(peixes) + " peixes");
            else {
                interface.setTexto("Venceu");
                vencedor = true;
            }
            interface.executar();
            //cout << deslocamento.x << endl;
        }

        void Jogador::tratarEventos() {
            set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
            set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();
            if (numJog == 1) {
                if (teclasPressionadas.count(sf::Keyboard::A)) {
                    andar(false);
                } else if (teclasPressionadas.count(sf::Keyboard::D)) {
                    andar(true);
                } else {
                    parar();
                }
                if (teclasPressionadas.count(sf::Keyboard::W)) {
                    if (podePular) {
                        pular(1.0f);
                        podePular = false;
                    }
                }
                if (teclasSoltas.count(sf::Keyboard::W)) {
                    liberaPulo();
                }
                if (teclasSoltas.count(sf::Keyboard::Space)) {
                    ataque.atacar();
                }
            } else {
                if (teclasPressionadas.count(sf::Keyboard::Left)) {
                    andar(false);
                } else if (teclasPressionadas.count(sf::Keyboard::Right)) {
                    andar(true);
                } else {
                    parar();
                }
                if (teclasPressionadas.count(sf::Keyboard::Up)) {
                    if (podePular) {
                        pular(1.0f);
                        podePular = false;
                    }
                }
                if (teclasSoltas.count(sf::Keyboard::Up)) {
                    liberaPulo();
                }
                if (teclasSoltas.count(sf::Keyboard::Down)) {
                    ataque.atacar();
                }
            }
        }

        void Jogador::notificar() {
            tratarEventos();
        }
    }
}
