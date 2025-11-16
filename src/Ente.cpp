#include "Ente.h"

int Ente::nID(0);
Gerenciador::GerenciadorGrafico* Ente::pGGrafico(pGGrafico->getGerenciadorGrafico());

Ente::Ente(sf::RectangleShape* pF):
ID(nID),
pFig(pF),
pTxt(nullptr) {
    nID++;
}

Ente::Ente(sf::Text* pT):
ID(nID),
pFig(nullptr),
pTxt(pT) {
    nID++;
}
Ente::~Ente() {}

const int Ente::getId() const{
    return ID;
}

void Ente::desenhar() {
    if (pFig)
        pGGrafico->desenharEnte(pFig);
    else
        pGGrafico->desenharUI(pTxt);
}




