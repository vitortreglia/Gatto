#include "Jogo.h"

Jogo::Jogo():
pGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
pGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEvento()),
pGEstados(new Gerenciador::GerenciadorEstados())
{
    //pGGrafico->setLimitesCamera(fase.getLimitesFase());
}

Jogo::~Jogo() {}

void Jogo::executar() {
    pGEstados->iniciar();
    while (pGGrafico->verificaJanelaAberta()) {
        pGGrafico->limpaJanela();
        pGEvento->executar();
        pGEstados->atualizar();
        pGGrafico->mostraElementos();
        pGGrafico->resetaRelogio();
    }
}

