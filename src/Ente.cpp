#include "Ente.h"

Gerenciador::GerenciadorGrafico* Ente::pGGrafico(pGGrafico->getGerenciadorGrafico());

Ente::Ente(IDs::Ente_IDs id, sf::RectangleShape* pF):
ID(id),
pFig(pF)
{}

Ente::~Ente() {
    ID = IDs::Ente_IDs::vazio;
}

const IDs::Ente_IDs Ente::getId() const{
    return ID;
}

void Ente::desenhar() {
    pGGrafico->desenharEnte(pFig);
}




