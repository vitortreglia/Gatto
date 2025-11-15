#include "Animacao/Animacao.h"

Animacao::Animacao(std::string caminho) {
    setTextura(caminho);
}

Animacao::~Animacao() {

}

void Animacao::setTextura(std::string caminho) {
    textura.loadFromFile(caminho, {});
}

sf::Texture *Animacao::getTextura() {
    return &textura;
}
