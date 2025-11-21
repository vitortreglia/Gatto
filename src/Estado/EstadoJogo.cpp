#include "Estado/EstadoJogo.h"

#include "Estado/EstadoMenuPrincipal.h"
#include "Estado/EstadoPausa.h"
#include "Fase/FaseCidade.h"
#include "Fase/FaseJardim.h"
#include "Entidade/Entidade.h"

namespace Estados {
    EstadoJogo* EstadoJogo::pEstadoJogo(nullptr);

    EstadoJogo::EstadoJogo():
    pFase(nullptr),
    pJog1(nullptr),
    pJog2(nullptr),
    pontosP1(0),
    pontosP2(0) {
        Entidade::Personagem::Jogador::setGerenciadorEvento();
    }

    EstadoJogo *EstadoJogo::getEstadoJogo(void* args) {
        if (!pEstadoJogo)
            pEstadoJogo = new EstadoJogo();

        pEstadoJogo->iniciar(args);

        return pEstadoJogo;
    }

    //args:
    //[0]: 1 = novo jogo 2 = carregar jogo
    //[1]: num jogs (1 ou 2)
    //[2]: 1 = fase jardim 2 = fase cidade
    void EstadoJogo::iniciar(void *args) {
        if (args) {
            int* a = (int*)args;
            for (int i = 0; i < 3; i++)
                arg[i] = a[i];
            if (pJog1) {
                delete pJog1;
                pJog1 = nullptr;
            }
            if (pJog2) {
                delete pJog2;
                pJog2 = nullptr;
            }
            if (arg[0] == 2) {
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
                    if (pFase)
                        delete pFase;

                    if (arg[2] == 1) {
                        pFase = new Fase::FaseJardim(pJog1, pJog2, carregamento);
                    } else if (arg[2] == 2) {
                        pFase = new Fase::FaseCidade(pJog1, pJog2, carregamento);
                    }
                    carregamento.close();
                }
                catch (const std::runtime_error &e) {
                    cout << e.what() << endl;
                    *a = 2;
                    sair(a);
                }
            } else {
                pJog1 = new Entidade::Personagem::Jogador(1, pontosP1);
                if (arg[1] == 2) {
                    pJog2 = new Entidade::Personagem::Jogador(2, pontosP2);
                }
                if (pFase)
                    delete pFase;
                if (arg[2] == 1) {
                    pFase = new Fase::FaseJardim(pJog1, pJog2);
                } else if (arg[2] == 2) {
                    pFase = new Fase::FaseCidade(pJog1, pJog2);
                }
            }
        }
        pGEvento->inscrever(this);
        pJog1->observarEntrada();
        if (pJog2)
            pJog2->observarEntrada();
    }

    void EstadoJogo::sair(void *args) {
        int* a = static_cast<int*>(args);
        pGEvento->desinscrever(this);
        pJog1->ignorarEntrada();
        if (pJog2)
            pJog2->ignorarEntrada();
        switch (*a) {
            case 1:
                mudarEstado(EstadoPausa::getEstadoPausa(NULL));
                break;
            case 2:
                mudarEstado(EstadoMenuPrincipal::getEstadoMenuPrincipal(NULL));
                break;
        }
    }

    void EstadoJogo::tratarEventos() {
        set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();

        if (teclasSoltas.count(sf::Keyboard::P)) {
            int a = 1;
            sair(&a);
        } else if (teclasSoltas.count(sf::Keyboard::K)) {
            pFase->salvar();
        }
    }

    void EstadoJogo::atualizar() {
        pFase->executar();
        if (pJog1->getVencedor()) {
            arg[2] = 2;
            sf::sleep(sf::seconds(2));
            if (pFase->getFase() == 2) {
                int a = 2;
                sair(&a);
            }
            pJog1->ignorarEntrada();
            if (pJog2)
                pJog2->ignorarEntrada();
            pGEvento->desinscrever(this);
            iniciar(arg);
        }
        if (pJog2) {
            if (pJog2->getVencedor()) {
                arg[2] = 2;
                sf::sleep(sf::seconds(2));
                if (pFase->getFase() == 2) {
                    int a = 2;
                    sair(&a);
                }
                pJog1->ignorarEntrada();
                pJog2->ignorarEntrada();
                pGEvento->desinscrever(this);
                iniciar(arg);
            }
        }
    }

    void EstadoJogo::desenhar() {

    }

}
