#include "Entidade/Personagem/Inimigo/Cachorro.h"
#include "Entidade/Itens/Projetil.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Ente_IDs.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {

            Cachorro::Cachorro(float x, float y) :
            ataque(1, 3.0f),
            Inimigo(0, 150.0f, {150.0f, 100.0f}, x, y-100, 4),
            raioPercepcaoX(300.0f),
            raioAtaque(230.0f),
            velocidade(150.0f),
            pProjetil(nullptr),
            tempoPatrulha(0)
                {
                textura.inserirTextura("parado", "Data/Imagens/cachorro.png");
                corpo.setFillColor(sf::Color(139, 69, 19));
                vMax.x = velocidade;
                andar(true);
                textura.setAnimacao("parado");
            }

            Cachorro::~Cachorro() {

            }
            void Cachorro::atualizaMaldade() {

                if (nivelMaldade <= 0) {
                    fatorFuria = 1.0f;
                    raioPercepcaoX = 300.0f;
                    raioAtaque = 230.0f;
                }
                else if (nivelMaldade == 1) {
                    fatorFuria = 1.25;
                    raioPercepcaoX = 350.0f;
                    raioAtaque = 270.0f;
                }
                else if (nivelMaldade == 2) {
                    fatorFuria = 1.5;
                    raioPercepcaoX = 400.0f;
                    raioAtaque = 300.0f;
                }
                else {
                    fatorFuria = 2.0f;
                    raioPercepcaoX = 450.0f;
                    raioAtaque = 350.0f;
                }
                    vMax.x = velocidade * fatorFuria;
            }

            void Cachorro::patrulhar() {
                tempoPatrulha += tempoFrame;
                if (tempoPatrulha > 2.0f) {
                    tempoPatrulha = 0.0f;
                    andar(!direita);
                }
            }
            void Cachorro::perseguir() {
                if (!pJog1)
                    return;

                sf::Vector2f posJog = pJog1->getPosicao();
                sf::Vector2f pos = getPosicao();
                float dx = posJog.x - pos.x;

                andar(dx > 0.0f);
            }

            void Cachorro::setProjetil(Itens::Projetil *pProj) {
                pProjetil = pProj;
                if (pProjetil) {
                    pProjetil->setAtivo(false);
                    pProjetil->setDirecao(direita);
                    pProjetil->setPosicao(getPosicao());
                }
            }

            void Cachorro::atirarOsso() {

                if (!pProjetil)
                    return;

                if (!ataque.getAtacando()) {
                    ataque.atacar();
                }

                int probAumentar;
                probAumentar= 10 + nivelMaldade * 15;
                if (probAumentar > 70)
                    probAumentar = 70;

                int sorteio;
                sorteio = std::rand() % 100;
                if (sorteio < probAumentar) {
                    nivelMaldade++;
                    atualizaMaldade();
                }

                pProjetil->setAtivo(true);
                pProjetil->setDirecao(direita);

                sf::Vector2f pos = getPosicao();
                sf::Vector2f tam = getTamanho();

                if (direita)
                    pos.x += tam.x * 0.5f;
                else
                    pos.x -= tam.x * 0.5f;

                pos.y += tam.y * 0.3f;

                pProjetil->setPosicao(pos);
                ataque.liberaAtaque();
                }

            void Cachorro::mover() {

                atualizaMaldade();

                Jogador* jogadorAlvo = nullptr;

                if (pJog1 && pJog2) {
                    sf::Vector2f posCao = getPosicao();
                    sf::Vector2f posJogador1 = pJog1->getPosicao();
                    sf::Vector2f posJogador2 = pJog2->getPosicao();

                    float deltaX1 = posJogador1.x - posCao.x;
                    float deltaY1 = posJogador1.y - posCao.y;
                    float distancia1 = deltaX1 * deltaX1 + deltaY1 * deltaY1;

                    float deltaX2 = posJogador2.x - posCao.x;
                    float deltaY2 = posJogador2.y - posCao.y;
                    float distancia2 = deltaX2 * deltaX2 + deltaY2 * deltaY2;

                    if (distancia1 <= distancia2) {
                        jogadorAlvo = pJog1;
                    }
                    else {
                        jogadorAlvo = pJog2;
                    }
                }

                else if (pJog1) {
                    jogadorAlvo = pJog1;
                }

                else if (pJog2) {
                    jogadorAlvo = pJog2;
                }

                if (!jogadorAlvo) {
                    patrulhar();
                    atualizarPos();
                    return;
                }

                sf::Vector2f posJogador  = jogadorAlvo->getPosicao();
                sf::Vector2f posCachorro = getPosicao();

                float deltaX = posJogador.x - posCachorro.x;
                float deltaY = posJogador.y - posCachorro.y;

                float distanciaX;
                if (deltaX < 0.0f) {
                    distanciaX = -deltaX;
                }
                else {
                    distanciaX = deltaX;
                }

                float distanciaY;

                if (deltaY < 0.0f) {
                    distanciaY = -deltaY;
                }
                else {
                    distanciaY = deltaY;
                }

                if (distanciaX <= raioPercepcaoX && distanciaY <= 100) {

                    if (deltaX > 10.0f) {
                        andar(true);
                    }
                    else if (deltaX < -10.0f) {
                        andar(false);
                    } else {
                            parar();
                    }

                    if (distanciaX <= raioAtaque && distanciaY <= 200.0f) {
                    atirarOsso();
                    }
                }
                else {
                    patrulhar();
                }
                    atualizarPos();
            }

            void Cachorro::danificar(Jogador* jogador) {
                if (!jogador)
                    return;

                if (jogador->getImunidadeDano())
                    return;

                int dano = ataque.getDano();

                int chanceDanoExtra = 0;

                if (nivelMaldade == 1) {
                    chanceDanoExtra = 15;
                }
                else if (nivelMaldade == 2) {
                    chanceDanoExtra = 30;
                }
                else if (nivelMaldade >= 3) {
                    chanceDanoExtra = 50;
                }

                int sorteio = rand() % 100;
                if (sorteio < chanceDanoExtra) {
                    dano += 1;
                }

                jogador->tomarDano(dano);

                nivelMaldade++;
                atualizaMaldade();
            }

            void Cachorro::executar() {
                textura.animar(getDireita());
                mover();
                verificaVidas();
            }

            void Cachorro::lerDataBuffer() {
                Inimigo::lerDataBuffer();
                entrada >> tempoPatrulha;
            }

            void Cachorro::carregar(istream &entrada) {
                this->entrada.rdbuf(entrada.rdbuf());
                lerDataBuffer();
            }

            void Cachorro::salvarDataBuffer() {
                buffer << "cachorro ";
                Inimigo::salvarDataBuffer();
                buffer << tempoPatrulha << endl;
            }

            void Cachorro::salvar(ostream &saida) {
                buffer.rdbuf(saida.rdbuf());
                salvarDataBuffer();
            }

        }
    }
}
