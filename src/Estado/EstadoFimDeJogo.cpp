#include "Estado/EstadoFimDeJogo.h"

#include "Estado/EstadoMenuPrincipal.h"

namespace Estados {
    EstadoFimDeJogo* EstadoFimDeJogo::pEstadoF(nullptr);

    EstadoFimDeJogo::EstadoFimDeJogo():
    pMenu(nullptr),
    pontVencedor(0){}

    EstadoFimDeJogo *EstadoFimDeJogo::getEstadoFimDeJogo(void *args) {
        if (pEstadoF)
            delete pEstadoF;
        pEstadoF = new EstadoFimDeJogo();
        pEstadoF->iniciar(args);
        return pEstadoF;
    }

    void EstadoFimDeJogo::iniciar(void *args) {
        pGEvento->inscrever(this);
        int* a = static_cast<int*>(args);
        if (pMenu)
            delete pMenu;
        pMenu = new Menu::MenuFimDeJogo(a[1]);
        pontVencedor = a[2];
    }

    void EstadoFimDeJogo::sair(void *args) {
        pGEvento->desinscrever(this);
        nome = pMenu->getNome();
        int p;
        string n;
        if (nome != "" && pontVencedor != 0) {
            multimap<int, string, std::greater<int>> ranking;
            ranking.insert({pontVencedor, nome});
            ifstream entradaRanking("Data/Ranking/ranking.dat");
            if (entradaRanking.is_open()) {
                while (entradaRanking >> n >> p) {
                    if (n != "" && p != 0) {
                        ranking.insert({p, n});
                        n = "";
                        p = 0;
                    }
                }
                entradaRanking.close();
            }
            ofstream saidaRanking("Data/Ranking/ranking.dat", std::ios::out | std::ios::trunc);
            if (saidaRanking.is_open()) {
                int i = 0;
                for (multimap<int, string>::const_iterator it = ranking.begin();
                    it != ranking.end() && i < 10; it++) {
                        saidaRanking << (*it).second << ' ' << (*it).first << endl;
                        i++;
                }
                saidaRanking.close();
            }
        }
        mudarEstado(EstadoMenuPrincipal::getEstadoMenuPrincipal(NULL));
    }

    void EstadoFimDeJogo::tratarEventos() {
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();
        if (!pMenu->getDigitando()) {
            if (pMenu->tratarCliques(pGEvento->getClique())) {
                if (pMenu->getSelecao() == 0) {
                    pMenu->digitar();
                } else if (pMenu->getSelecao() == 1) {
                    sair(NULL);
                }
            }
        } else {
            if (teclasSoltas.count(sf::Keyboard::Enter)) {
                pMenu->pararDigitar();
            }
            if (pMenu->tratarCliques(pGEvento->getClique())) {
                if (pMenu->getSelecao() == 1) {
                    pMenu->pararDigitar();
                    sair(NULL);
                }
            }
        }
    }

    void EstadoFimDeJogo::atualizar() {
        pMenu->executar();
    }

}
