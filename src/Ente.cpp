#include "Ente.h"

Gerenciador::GerenciadorGrafico* Ente::pGGrafico(pGGrafico->getGerenciadorGrafico());

Ente::Ente(IDs::IDs id, sf::RectangleShape* pF):
ID(id),
pFig(pF)
{}

Ente::~Ente() {
    ID = IDs::IDs::vazio;
}

const IDs::IDs Ente::getId() const{
    return ID;
}

void Ente::desenhar() {
    pGGrafico->desenharEnte(pFig);
}




