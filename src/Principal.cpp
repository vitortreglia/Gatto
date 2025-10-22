#include "Principal.h"

Principal::Principal():
pGGrafico(pGGrafico->getGerenciadorGrafico())
{
    executar();
}

Principal::~Principal() {}

void Principal::executar() {
    while (pGGrafico->verificaJanelaAberta()) {
        sf::Event event;
        while (pGGrafico->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                pGGrafico->fecharJanela();
            }
        }
        pGGrafico->limpaJanela();
        pGGrafico->mostraElementos();
    }
}

