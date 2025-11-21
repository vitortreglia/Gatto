#include "Estado/EstadoMenuPrincipal.h"

#include "Estado/EstadoJogo.h"

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
        if (!pMenu)
            pMenu = new Menu::MenuPrincipal();
        pGEvento->inscrever(this);
    }

    void EstadoMenuPrincipal::sair(void *args) {
        pGEvento->desinscrever(this);
        int* arg = static_cast<int*>(args);
        mudarEstado(static_cast<Estado*>(EstadoJogo::getEstadoJogo(static_cast<void*>(arg))));
    }

    void EstadoMenuPrincipal::tratarEventos() {
        set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();
        if (teclasSoltas.count(sf::Keyboard::W)) {
            pMenu->anterior();
        } else if (teclasSoltas.count(sf::Keyboard::S)) {
            pMenu->proximo();
        } else if (teclasSoltas.count(sf::Keyboard::Enter)) {
            int args[] = {1, 1, 1};
            if (pMenu->getSelecao() == 0) {
                args[0] = 1;
            } else if (pMenu->getSelecao() == 1){
                args[1] = 2;
            } else {
                args[0] = 2;
            }
            sair(args);
        }
    }

    void EstadoMenuPrincipal::atualizar() {
        pMenu->executar();
    }

    void EstadoMenuPrincipal::desenhar() {

    }

}
