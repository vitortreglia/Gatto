#include "Principal.h"

Principal::Principal():
pGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
pGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEvento()),
jog()
{
    pGEvento->setJogador(&jog);
    executar();
}

Principal::~Principal() {}

void Principal::executar() {
    while (pGGrafico->verificaJanelaAberta()) {
        pGGrafico->limpaJanela();
        pGGrafico->desenhaElemento(sf::RectangleShape(sf::Vector2f(100.0f, 100.0f)));
        jog.atualizar();
        pGGrafico->mostraElementos();
        pGEvento->executar();
        pGGrafico->resetaRelogio();
    }
}

