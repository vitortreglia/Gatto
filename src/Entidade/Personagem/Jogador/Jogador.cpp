#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Entidade {
    namespace Personagem {
        Gerenciador::GerenciadorEvento* Jogador::pGEvento(nullptr);

        Jogador::Jogador(int nJog, int p):
        Personagem(600.0f, sf::Vector2f(100, 100), 1600, 4500, 7),
        pontos(p),
        numJog(nJog),
        vencedor(false),
        ataque(1, 0.1f),
        podePular(true),
        peixes(0),
        deslocAtaque(0.0f),
        interface("oiii", 30, 20, 50),
        imunidadeDano(false)
        {
            if (numJog == 2) {
                textura.inserirTextura("parado", "Data/Imagens/Gato2/parado.png");
                textura.inserirTextura("andando", "Data/Imagens/Gato2/andando.png");
                textura.inserirTextura("pulando", "Data/Imagens/Gato2/pulando1.png");
                textura.inserirTextura("caindo", "Data/Imagens/Gato2/pulando2.png");
                textura.inserirTextura("dano", "Data/Imagens/Gato2/tomandoDano.png");
                textura.inserirTextura("atacando", "Data/Imagens/Gato2/arranhando.png");
                interface.setPosicao(1020, 50);
            } else {
                textura.inserirTextura("parado", "Data/Imagens/Gato1/parado.png");
                textura.inserirTextura("andando", "Data/Imagens/Gato1/andando.png");
                textura.inserirTextura("pulando", "Data/Imagens/Gato1/pulando1.png");
                textura.inserirTextura("caindo", "Data/Imagens/Gato1/pulando2.png");
                textura.inserirTextura("dano", "Data/Imagens/Gato1/tomandoDano.png");
                textura.inserirTextura("atacando", "Data/Imagens/Gato1/arranhando.png");
            }
            textura.setAnimacao("parado");
        }

        Jogador::~Jogador() {
        }

        bool Jogador::getVencedor() {
            return vencedor;
        }

        void Jogador::setGerenciadorEvento() {
            pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        }

        void Jogador::observarEntrada() {
            if (pGEvento)
                pGEvento->inscrever(this);
            else
                cout << "erro ao observar entrada" << endl;
        }

        void Jogador::ignorarEntrada() {
            if (pGEvento)
                pGEvento->desinscrever(this);
        }

        void Jogador::liberaPulo() {
            podePular = true;
        }

        void Jogador::pular(float multiplicador) {
            if (noChao) {
                if (!sofrendoDano)
                    textura.setAnimacao("pulando");
                deslocamento.y = -30.0f * multiplicador;
                estaNoChao(false);
            }
        }

        void Jogador::coletarPeixe(Itens::Peixe *pPeixe) {
            pPeixe->setAtivo(false);
            peixes++;
            pontuar(500);
            if (numVidas < 7)
                numVidas++;
        }

        const bool Jogador::perderPeixe() {
            if (peixes > 0) {
                peixes--;
                pontuar(-500);
                return true;
            }
            return false;
        }

        const bool Jogador::getImunidadeDano() const {
            return imunidadeDano;
        }

        void Jogador::colidir(Inimigo::Inimigo* pInimigo, sf::Vector2f colisao) {
            if (colisao.y < 0.0f) {
                pular(1.0f);
                pInimigo->tomarDano(1);
                pInimigo->setUltimoAtacante(this);
            } else if (ataque.getAtacando() || deslocAtaque != 0.0f) {
                if (getDireita()) {
                    if (colisao.x < 0.0f) {
                        pInimigo->tomarDano(ataque.getDano());
                        pInimigo->setUltimoAtacante(this);
                    } else {
                        pInimigo->danificar(this);
                    }
                } else if (colisao.x > 0.0f) {
                        pInimigo->tomarDano(ataque.getDano());
                        pInimigo->setUltimoAtacante(this);
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
                imunidadeDano = true;
                Personagem::tomarDano(dano);
            }
        }

        void Jogador::verificaVidas() {
            if (numVidas <= 0) {
                cout << "morreu " << endl;
                setAtivo(false);
                pGGrafico->setMultiplayer(false);
            } else if (imunidadeDano) {
                textura.setAnimacao("dano");
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

        void Jogador::pontuar(int p) {
            pontos += p;
        }

        int Jogador::getPontuacao() {
            return pontos;
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
            if (noChao && !andando && !sofrendoDano && !ataque.getAtacando())
                textura.setAnimacao("parado");
            else if (deslocamento.y > 0 && !noChao)
                textura.setAnimacao("caindo");
            textura.animar(getDireita());
            pGGrafico->moveCamera(getPosicao(), numJog);
            mover();
            if (peixes < 3)
                interface.setTexto(std::to_string(numVidas) + " vidas | " + std::to_string(peixes) + " peixes"
                    + "\n" + std::to_string(pontos));
            else {
                interface.setTexto("Venceu");
                vencedor = true;
            }
            interface.executar();
        }

        void Jogador::tratarEventos() {
            set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
            set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();
            if (numJog == 1) {
                if (teclasPressionadas.count(sf::Keyboard::A)) {
                    textura.setAnimacao("andando");
                    andar(false);
                } else if (teclasPressionadas.count(sf::Keyboard::D)) {
                    textura.setAnimacao("andando");
                    andar(true);
                } else {
                    parar();
                }
                if (teclasPressionadas.count(sf::Keyboard::W)) {
                    if (podePular) {
                        textura.setAnimacao("pulando");
                        pular(1.0f);
                        podePular = false;
                    }
                }
                if (teclasSoltas.count(sf::Keyboard::W)) {
                    liberaPulo();
                }
                if (teclasSoltas.count(sf::Keyboard::Space)) {
                    textura.setAnimacao("atacando");
                    ataque.atacar();
                }
            } else {
                if (teclasPressionadas.count(sf::Keyboard::Left)) {
                    textura.setAnimacao("andando");
                    andar(false);
                } else if (teclasPressionadas.count(sf::Keyboard::Right)) {
                    textura.setAnimacao("andando");
                    andar(true);
                } else {
                    parar();
                }
                if (teclasPressionadas.count(sf::Keyboard::Up)) {
                    if (podePular) {
                        textura.setAnimacao("pulando");
                        pular(1.0f);
                        podePular = false;
                    }
                }
                if (teclasSoltas.count(sf::Keyboard::Up)) {
                    liberaPulo();
                }
                if (teclasSoltas.count(sf::Keyboard::Down)) {
                    textura.setAnimacao("atacando");
                    ataque.atacar();
                }
            }
        }

        void Jogador::notificar() {
            tratarEventos();
        }

        void Jogador::lerDataBuffer() {
            Personagem::lerDataBuffer();
            entrada >> pontos >> numJog >> podePular >> peixes >> imunidadeDano;
        }

        void Jogador::carregar(istream &entrada) {
            this->entrada.rdbuf(entrada.rdbuf());
            lerDataBuffer();
        }

        void Jogador::salvarDataBuffer() {
            Personagem::salvarDataBuffer();
            buffer << pontos << ' ' << numJog << ' ' << podePular << ' ' << peixes << ' ' << imunidadeDano << endl;
        }

        void Jogador::salvar(ostream& saida) {
            buffer.rdbuf(saida.rdbuf());
            salvarDataBuffer();
        }

    }
}
