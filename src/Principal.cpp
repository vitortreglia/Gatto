#include "Principal.h"

Principal::Principal():
pGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
pGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEvento())
{
    executar();
}

Principal::~Principal() {}

void Principal::executar() {
    while (pGGrafico->verificaJanelaAberta()) {
        pGGrafico->limpaJanela();
        pGEvento->executar();
        fase.executar();
        pGGrafico->mostraElementos();
        pGGrafico->resetaRelogio();
    }
}

