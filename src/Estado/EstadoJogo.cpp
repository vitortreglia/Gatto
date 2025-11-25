#include "Estado/EstadoJogo.h"

#include "Estado/EstadoMenuPrincipal.h"
#include "Estado/EstadoPausa.h"
#include "Fase/FaseCidade.h"
#include "Fase/FaseJardim.h"
#include "Entidade/Entidade.h"
#include "Estado/EstadoFimDeJogo.h"

namespace Estados {
    EstadoJogo* EstadoJogo::pEstadoJogo(nullptr);

    EstadoJogo::EstadoJogo():
    pFase(nullptr),
    pJog1(nullptr),
    pJog2(nullptr),
    pontosP1(0),
    pontosP2(0) {}

    EstadoJogo *EstadoJogo::getEstadoJogo(void* args) { // singleton do estado de jogo
        if (!pEstadoJogo) // se nao existe ainda, cria
            pEstadoJogo = new EstadoJogo();
        pEstadoJogo->iniciar(args); // sempre chama pra configurar
        return pEstadoJogo; // retorna ponteiro

    }

    //args:
    //[0]: 1 = novo jogo 2 = carregar jogo -1 = salvar e sair
    //[1]: num jogs (1 ou 2)
    //[2]: 1 = fase jardim 2 = fase cidade
    void EstadoJogo::iniciar(void *args) {
        abort = false;
        pGEvento->inscrever(this);
        if (args) {
            int* a = (int*)args;
            for (int i = 0; i < 3; i++)
                arg[i] = a[i];

            if (arg[0] == -1) {
                pGEvento->desinscrever(this);
                pFase->salvar();
                abort = true;
            } else
                // apaga as instancias antigas jogadores e fase
                    if (pJog1) {
                        delete pJog1;
                        pJog1 = nullptr;
                    }
            if (pJog2) {
                delete pJog2;
                pJog2 = nullptr;
            }
            if (pFase) {
                delete pFase;
                pFase = nullptr;
            }

            if (arg[0] == 2) {
                // se carrregar jogo abre o arquivo
                try {
                    ifstream carregamento("Data/Fases/save.txt");

                    if (!carregamento.is_open())
                        throw std::runtime_error("nao ha jogo salvo");

                    carregamento >> arg[1] >> arg[2];

                    pJog1 = new Entidade::Personagem::Jogador(1, pontosP1);

                    pJog1->carregar(carregamento);
                    if (arg[1] == 2) {
                        pJog2 = new Entidade::Personagem::Jogador(2, pontosP2);
                        pJog2->carregar(carregamento);
                    }
                    if (pFase) // cria a fase correta passando o arquivo
                        delete pFase;
                    if (arg[2] == 1) {
                        pFase = new Fase::FaseJardim(pJog1, pJog2, carregamento);
                    } else if (arg[2] == 2) {
                        pFase = new Fase::FaseCidade(pJog1, pJog2, carregamento);
                    }
                    carregamento.close();
                    if (pJog1)
                        pJog1->observarEntrada();
                    if (pJog2)
                        pJog2->observarEntrada();
                }
                catch (const std::runtime_error &e) {
                    cout << e.what() << endl;
                    abort = true;
                }
            } else { // cria novo jogo
                pJog1 = new Entidade::Personagem::Jogador(1, pontosP1);
                if (arg[1] == 2) {
                    pJog2 = new Entidade::Personagem::Jogador(2, pontosP2);
                }
                if (arg[2] == 1) {
                    pFase = new Fase::FaseJardim(pJog1, pJog2);
                } else if (arg[2] == 2) {
                    pFase = new Fase::FaseCidade(pJog1, pJog2);
                }
                if (pJog1)
                    pJog1->observarEntrada();
                if (pJog2)
                    pJog2->observarEntrada();
            }

        } else {
            if (pJog1)
                pJog1->observarEntrada();
            if (pJog2)
                pJog2->observarEntrada();
        }
    }

    void EstadoJogo::sair(void *args) {
        pontosP1 = 0;
        pontosP2 = 0;
        int* a = static_cast<int*>(args);
        switch (a[0]) {
            case -1:
                mudarEstado(EstadoMenuPrincipal::getEstadoMenuPrincipal(NULL));
                break;
            case 1:
                mudarEstado(EstadoPausa::getEstadoPausa(NULL));
                break;
            case 2:
                mudarEstado(EstadoFimDeJogo::getEstadoFimDeJogo(args));
                break;
        }
    }

    void EstadoJogo::tratarEventos() { // atalhos durante o jogo
        set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();

        if (teclasSoltas.count(sf::Keyboard::P)) { // se soltar p, pausa
            int a = 1;
            pGEvento->desinscrever(this);
            pJog1->ignorarEntrada();
            if (pJog2)
                pJog2->ignorarEntrada();
            sair(&a);
        } else if (teclasSoltas.count(sf::Keyboard::K)) { // se soltar k, apenas salva a fase
            pFase->salvar();
        }
    }

    void EstadoJogo::verificaFimJogo() { // dececta vitoria ou game over
        int fim = 0;
        if (pJog1) {
            if (pJog1->getVencedor()) {
                fim = 1;
            } else if (!pJog2 && !pJog1->estaAtivo()) {
                fim = 2;
            }
        }
        if (pJog2) {
            if (pJog2->getVencedor()) {
                fim = 1;
            }
        }
        if (pJog2 && !pJog1->estaAtivo() && !pJog2->estaAtivo())
            fim = 2;

        if (fim) {
            pJog1->ignorarEntrada();
            pontosP1 = pJog1->getPontuacao();
            if (pJog2) {
                pJog2->ignorarEntrada();
                pontosP2 = pJog2->getPontuacao();
            }
            pGEvento->desinscrever(this);
            sf::sleep(sf::seconds(1));
            if (fim == 1) {
                if (pFase->getFase() == 2) {
                    arg[0] = 2;
                    if (pontosP1 > pontosP2) {
                        arg[1] = 1;
                        arg[2] = pontosP1;
                    } else {
                        arg[1] = 2;
                        arg[2] = pontosP2;
                    }
                    sair(arg);
                } else {
                    arg[0] = 1;
                    arg[2] = 2;
                    iniciar(arg);
                }
            } else {
                arg[0] = 2;
                if (pontosP1 > pontosP2) {
                    arg[1] = 1;
                    arg[2] = pontosP1;
                } else {
                    arg[1] = 2;
                    arg[2] = pontosP2;
                }
                sair(arg);
            }
        }
    }

    void EstadoJogo::atualizar() {
        if (abort) {   // se abort for true volta pro menu
            int a = -1;
            sair(&a);
        }
        if (pFase)
            pFase->executar();
        verificaFimJogo();
    }
}
