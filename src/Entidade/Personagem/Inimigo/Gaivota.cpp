#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Entidade/Personagem/Inimigo/EstadoPatrulha.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {


            Gaivota::Gaivota(float x, float y):
            ataque(1, 1.0f),
            Inimigo(0, 120.0f, {80.0f, 50.0f},x, y, 2),
            amplitude(10.0f),
            frequencia(6.0f),
            tempo(0.0f),
            possuiPeixe(false),
            estado(nullptr),
            raioPercepcaoX(280),
            raioPercepcaoY(300),
            pPeixe(nullptr)
            {
                textura.inserirTextura("voando", "Data/Imagens/Gaivota/voando.png");
                textura.inserirTextura("rasante", "Data/Imagens/Gaivota/rasante.png");
                textura.inserirTextura("dano", "Data/Imagens/Gaivota/dano.png");
                andar(true);
                setEstado(dynamic_cast <EstadoGaivota*>(new EstadoPatrulha(this)));
                setVoador(true);
                textura.setAnimacao("voando");
            }

            Gaivota::~Gaivota(){}

            void Gaivota::setPeixe(Itens::Peixe *pP) {
                pPeixe = pP;
            }

            void Gaivota::danificar(Jogador *pJ) {
                if (!pJ->getImunidadeDano() && !sofrendoDano) {
                    nivelMaldade++;
                    if (nivelMaldade > 1 && !possuiPeixe && ataque.getAtacando()) {
                        possuiPeixe = pJ->perderPeixe();
                    }
                    pJ->tomarDano(1);
                }
            }

            void Gaivota::mover() {
                deslocamento.y = std::sin(tempo * frequencia * M_PI) * amplitude;
                atualizarPos();
                tempo += tempoFrame;
                if (tempo > 3.0f) {
                    parar();
                    andar(!direita);
                    tempo = 0.0f;
                }
            }

            Jogador* Gaivota::patrulhar(float dt) {
                textura.setAnimacao("voando");
                mover();

                const sf::Vector2f& posJog = pJog1->getPosicao();
                sf::Vector2f posicao = getPosicao();
                float dx = posJog.x - posicao.x;
                float dy = posJog.y - posicao.y;
                float adx = std::fabs(dx);
                float ady = std::fabs(dy);

                if (adx < raioPercepcaoX && ady < raioPercepcaoY) {
                    textura.setAnimacao("rasante");
                    return pJog1;
                }

                if (pJog2) {
                    const sf::Vector2f& posJog2 = pJog2->getPosicao();
                    posicao = getPosicao();
                    dx = posJog2.x - posicao.x;
                    dy = posJog2.y - posicao.y;
                    adx = std::fabs(dx);
                    ady = std::fabs(dy);

                    if (adx < raioPercepcaoX && ady < raioPercepcaoY) {
                        textura.setAnimacao("rasante");
                        return pJog2;
                    }
                }

                return nullptr;
            }

            void Gaivota::setEstado(EstadoGaivota *pEstado) {
                if (pEstado) {
                    estado = pEstado;
                }
            }

            void Gaivota::verificaVidas() {
                if (numVidas <= 0) {
                    if (pUltimoAtacante)
                        pUltimoAtacante->pontuar(nivelMaldade * 100 + 100);
                    if (possuiPeixe) {
                        pPeixe->setAtivo(true);
                        pPeixe->setPosicao({x, y});
                    }
                    setAtivo(false);
                } else if (sofrendoDano) {
                    corpo.setFillColor(sf::Color::Red);
                    tempoDano += tempoFrame;
                    if (tempoDano > 0.5f) {
                        sofrendoDano = false;
                        tempoDano = 0.0f;
                        corpo.setFillColor(sf::Color::White);
                    }
                }
            }

            void Gaivota::executar() {
                textura.animar(getDireita());
                verificaVidas();
                estado->executar(tempoFrame);
            }

            void Gaivota::lerDataBuffer() {
                Inimigo::lerDataBuffer();
                float t;
                float vax;
                float vay;
                float tatk;
                entrada >> tempo >> possuiPeixe >> t >> vax >> vay >> tatk;
                if (vax == 0 && vay == 0) {
                    setEstado(dynamic_cast <EstadoGaivota*>(new EstadoPatrulha(this)));
                } else {
                    setEstado(dynamic_cast <EstadoGaivota*>(new EstadoRasante(this, nullptr)));
                    if (t < 1.0f) {
                        ataque.atacar();
                        ataque.setTempoAtaque(tatk);
                    }
                    static_cast<EstadoRasante*>(estado)->setTempo(t);
                    static_cast<EstadoRasante*>(estado)->setVetorAtaque({vax, vay});
                }
            }

            void Gaivota::carregar(istream &entrada) {
                this->entrada.rdbuf(entrada.rdbuf());
                lerDataBuffer();
            }

            void Gaivota::salvarDataBuffer() {
                buffer << "gaivota ";
                Inimigo::salvarDataBuffer();
                buffer << tempo << ' ' << possuiPeixe << ' ';
                try {
                    EstadoRasante* rasante = dynamic_cast<EstadoRasante*>(estado);
                    if (!rasante)
                        throw std::runtime_error("nao eh rasante");
                    buffer << static_cast<EstadoRasante*>(estado)->getTempo() << ' ' <<
                        static_cast<EstadoRasante*>(estado)->getVetorAtaque().x << ' ' <<
                            static_cast<EstadoRasante*>(estado)->getVetorAtaque().y << ' '
                                << ataque.getTempoAtaque() << endl;
                }
                catch (std::exception &e) {
                    buffer << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << endl;
                }
            }

            void Gaivota::salvar(ostream &saida) {
                buffer.rdbuf(saida.rdbuf());
                salvarDataBuffer();
            }

        }
    }
}
