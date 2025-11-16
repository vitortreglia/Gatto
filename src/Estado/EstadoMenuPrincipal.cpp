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

        if (teclasSoltas.count(sf::Keyboard::Enter)) {
            int args[] = {1, 1, 1};
            sair(args);
        } else if (teclasSoltas.count(sf::Keyboard::Num2)) {
            int args[] = {2, 1, 1};
            sair(args);
        }
    }

    void EstadoMenuPrincipal::atualizar() {
        pMenu->executar();
    }

    void EstadoMenuPrincipal::desenhar() {

    }

}
