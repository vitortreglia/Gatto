#include "Principal.h"

Principal::Principal():
pGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
pGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEvento()),
pGEstados(new Gerenciador::GerenciadorEstados())
{
    //pGGrafico->setLimitesCamera(fase.getLimitesFase());
}

Principal::~Principal() {}

void Principal::executar() {
    pGEstados->iniciar();
    while (pGGrafico->verificaJanelaAberta()) {
        pGGrafico->limpaJanela();
        pGEvento->executar();
        pGEstados->atualizar();
        pGGrafico->mostraElementos();
        pGGrafico->resetaRelogio();
    }
}

