#include "Ente.h"

Gerenciador::GerenciadorGrafico* Ente::pGGrafico(pGGrafico->getGerenciadorGrafico());

Ente::Ente(IDs::IDs id) {
    ID = id;
}

Ente::~Ente() {
    ID = IDs::IDs::vazio;
}

const IDs::IDs Ente::getId() const{
    return ID;
}



