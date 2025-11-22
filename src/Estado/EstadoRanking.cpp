#include "Estado/EstadoRanking.h"

#include "Estado/EstadoMenuPrincipal.h"
#include "Gerenciador/GerenciadorEvento.h"

namespace Estados {
    EstadoRanking* EstadoRanking::pEstadoRanking(nullptr);

    EstadoRanking::EstadoRanking():
    pMenu(nullptr){}

    EstadoRanking *EstadoRanking::getEstadoRanking(void *args) {
        if (!pEstadoRanking)
            pEstadoRanking = new EstadoRanking();
        pEstadoRanking->iniciar(args);
        return pEstadoRanking;
    }

    void EstadoRanking::iniciar(void *args) {
        pGEvento->inscrever(this);
        multimap<int, string, std::greater<int>> ranking;

        ifstream arq("Data/Ranking/Ranking.dat");
        if (arq.is_open()) {
            int p;
            string n;

            while (arq >> n >> p) {
                ranking.insert({p, n});
            }
            arq.close();
        } else {
            ranking.insert({0, "vazio"});
        }

        if (pMenu)
            delete pMenu;
        pMenu = new Menu::MenuRanking(ranking);
    }

    void EstadoRanking::sair(void *args) {
        pGEvento->desinscrever(this);
        mudarEstado(Estados::EstadoMenuPrincipal::getEstadoMenuPrincipal(NULL));
    }

    void EstadoRanking::tratarEventos() {
        if (pMenu->tratarCliques(pGEvento->getClique())) {
            if (pMenu->getSelecao() == 0) {
                sair(NULL);
            }
        }
    }

    void EstadoRanking::atualizar() {
        pMenu->executar();
    }

}
