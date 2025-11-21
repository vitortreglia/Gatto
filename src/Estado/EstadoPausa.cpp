#include "Estado/EstadoPausa.h"
#include "Estado/EstadoJogo.h"
#include "Estado/EstadoMenuPrincipal.h"

namespace Estados {
    EstadoPausa* EstadoPausa::pEstadoPausa(nullptr);

    EstadoPausa::EstadoPausa():
    pMenuPausa(nullptr)
    {}

    EstadoPausa *EstadoPausa::getEstadoPausa(void *args) {
        if (!pEstadoPausa)
            pEstadoPausa = new EstadoPausa();
        pEstadoPausa->iniciar(args);
        return pEstadoPausa;
    }

    void EstadoPausa::iniciar(void *args) {
        if (!pMenuPausa)
            pMenuPausa = new Menu::MenuPausa();
        pGEvento->inscrever(this);
    }

    void EstadoPausa::sair(void *args) {
        int* arg = static_cast<int*>(args);
        pGEvento->desinscrever(this);
        switch (*arg) {
            case 1:
                mudarEstado(EstadoJogo::getEstadoJogo(NULL));
                break;
            case 2:
                mudarEstado(EstadoMenuPrincipal::getEstadoMenuPrincipal(NULL));
                break;
        }
    }

    void EstadoPausa::tratarEventos() {
        set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();
        int arg;
        if (teclasSoltas.count(sf::Keyboard::W)) {
            pMenuPausa->anterior();
            cout << "detectou" << endl;
        } else if (teclasSoltas.count(sf::Keyboard::S)) {
            pMenuPausa->proximo();
        } else if (teclasSoltas.count(sf::Keyboard::Enter)) {
            int args;
            if (pMenuPausa->getSelecao() == 0) {
                args = 1;
            } else {
                args = 2;
            }
            sair(&args);
        }
    }

    void EstadoPausa::atualizar() {
        pMenuPausa->executar();
    }

    void EstadoPausa::desenhar() {

    }

}
