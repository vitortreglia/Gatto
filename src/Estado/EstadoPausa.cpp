#include "Estado/EstadoPausa.h"
#include "Estado/EstadoJogo.h"

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
        pGEvento->desinscrever(this);
        mudarEstado(EstadoJogo::getEstadoJogo(NULL));
    }

    void EstadoPausa::tratarEventos() {
        set<sf::Keyboard::Key> teclasPressionadas = pGEvento->getTeclasPressionadas();
        set<sf::Keyboard::Key> teclasSoltas = pGEvento->getTeclasSoltas();

        if (teclasSoltas.count(sf::Keyboard::P)) {
            sair(NULL);
        }
    }

    void EstadoPausa::atualizar() {
        pMenuPausa->executar();
    }

    void EstadoPausa::desenhar() {

    }

}
