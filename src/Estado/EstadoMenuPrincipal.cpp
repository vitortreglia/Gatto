#include "Estado/EstadoMenuPrincipal.h"

#include "Estado/EstadoJogo.h"
#include "Estado/EstadoRanking.h"

namespace Estados {
    EstadoMenuPrincipal* EstadoMenuPrincipal::pEstadoMenu(nullptr);

    EstadoMenuPrincipal::EstadoMenuPrincipal():
    pMenu(nullptr)
    {}

    EstadoMenuPrincipal *EstadoMenuPrincipal::getEstadoMenuPrincipal(void *args) {
        if (!pEstadoMenu)
            pEstadoMenu = new EstadoMenuPrincipal();
        pEstadoMenu->iniciar(args);
        return pEstadoMenu;
    }

    void EstadoMenuPrincipal::iniciar(void *args) {
        if (pMenu)
            delete pMenu;
        pMenu = new Menu::MenuPrincipal();
        pGEvento->inscrever(this);
    }

    void EstadoMenuPrincipal::sair(void *args) {
        pGEvento->desinscrever(this);
        int* arg = static_cast<int*>(args);
        if (arg[0] == 3) {
            mudarEstado(EstadoRanking::getEstadoRanking(static_cast<void*>(arg)));
        } else {
            mudarEstado(EstadoJogo::getEstadoJogo(static_cast<void*>(arg)));
        }
    }

    void EstadoMenuPrincipal::tratarEventos() {
        set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();
        if (pMenu->tratarCliques(pGEvento->getClique())) {
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
            cout << "enter" << endl;
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
