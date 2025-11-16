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
        if (teclasSoltas.count(sf::Keyboard::P)) {
            arg = 1;
            sair(&arg);
        } else if (teclasSoltas.count(sf::Keyboard::Q)) {
            arg = 2;
            sair(&arg);
        }
    }

    void EstadoPausa::atualizar() {
        pMenuPausa->executar();
    }

    void EstadoPausa::desenhar() {

    }

}
