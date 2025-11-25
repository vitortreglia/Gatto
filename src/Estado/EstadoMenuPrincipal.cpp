#include "Estado/EstadoMenuPrincipal.h"

#include "Estado/EstadoJogo.h"
#include "Estado/EstadoRanking.h"

namespace Estados {
    EstadoMenuPrincipal* EstadoMenuPrincipal::pEstadoMenu(nullptr);

    EstadoMenuPrincipal::EstadoMenuPrincipal():
    pMenu(nullptr)
    {}

    EstadoMenuPrincipal *EstadoMenuPrincipal::getEstadoMenuPrincipal(void *args) {
        if (!pEstadoMenu)  // se ainda nao existe estadoMenu, cria
            pEstadoMenu = new EstadoMenuPrincipal();
        pEstadoMenu->iniciar(args); // chama sempre pra resetar menu
        return pEstadoMenu;
    }

    void EstadoMenuPrincipal::iniciar(void *args) { // monta menu principal
        if (pMenu) // se ja havia menu, deleta
            delete pMenu;
        pMenu = new Menu::MenuPrincipal(); // cria menu principal
        pGEvento->inscrever(this);     // inscreve no gerenciador de eventos
    }

    void EstadoMenuPrincipal::sair(void *args) { // troca para o proximo estado
        pGEvento->desinscrever(this);  // desinscreve de eventos
        int* arg = static_cast<int*>(args);
        if (arg[0] == 3) {
            mudarEstado(EstadoRanking::getEstadoRanking(static_cast<void*>(arg)));
        } else {
            mudarEstado(EstadoJogo::getEstadoJogo(static_cast<void*>(arg)));
        }
    }

    void EstadoMenuPrincipal::tratarEventos() { // le teclado/clique e decide ação
        set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();
        if (pMenu->tratarCliques(pGEvento->getClique())) {
            // se menu detecta clique valido, decide o que fazer:
            int args[] = {1, 1, 1};
            if (pMenu->getSelecao() == 0) {
                args[0] = 1;
            } else if (pMenu->getSelecao() == 1){
                args[1] = 2;
            } else if (pMenu->getSelecao() == 2) {
                args[0] = 2;
            } else {
                args[0] = 3;
            }
            sair(args);
        }
        if (teclasSoltas.count(sf::Keyboard::W)) {
            pMenu->anterior();
        } else if (teclasSoltas.count(sf::Keyboard::S)) {
            pMenu->proximo();
        } else if (teclasSoltas.count(sf::Keyboard::Enter)) {
            int args[] = {0, 1, 1};
            if (pMenu->getSelecao() == 0) {
                args[0] = 1;
            } else if (pMenu->getSelecao() == 1){
                args[1] = 2;
            } else if (pMenu->getSelecao() == 2) {
                args[0] = 2;
            } else {
                args[0] = 3;
            }
            sair(args);
        }
    }

    void EstadoMenuPrincipal::atualizar() {
        pMenu->executar();
    }

}
