#include "Principal.h"

Principal::Principal():
pGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
pGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEvento()),
pGEstados(new Gerenciador::GerenciadorEstados())
{
    //pGGrafico->setLimitesCamera(fase.getLimitesFase());
    executar();
}

Principal::~Principal() {}

void Principal::executar() {
    while (pGGrafico->verificaJanelaAberta()) {
        pGGrafico->limpaJanela();
        pGEvento->executar();
        pGEstados->atualizar();
        pGGrafico->mostraElementos();
        pGGrafico->resetaRelogio();
    }
}

