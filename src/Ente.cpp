#include "Ente.h"

Gerenciador::GerenciadorGrafico* Ente::pGGrafico(pGGrafico->getGerenciadorGrafico());

Ente::Ente(IDs::Ente_IDs id, sf::RectangleShape* pF):
ID(id),
pFig(pF),
pTxt(nullptr)
{}

Ente::Ente(IDs::Ente_IDs id, sf::Text* pT):
ID(id),
pFig(nullptr),
pTxt(pT)
{}
Ente::~Ente() {
    ID = IDs::Ente_IDs::vazio;
}

const IDs::Ente_IDs Ente::getId() const{
    return ID;
}

void Ente::desenhar() {
    if (pFig)
        pGGrafico->desenharEnte(pFig);
    else
        pGGrafico->desenharUI(pTxt);
}




