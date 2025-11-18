#include "Animacao/Animacao.h"

Animacao::Animacao():
tempoAnimacao(0),
frame(0){}

Animacao::~Animacao() {

}

void Animacao::inserirTextura(string nome, string caminho) {
    sf::Texture t;
    texturaAtual = nome;
    t.loadFromFile(caminho);
    t.setRepeated(true);
    texturas.insert({nome, t});
}

void Animacao::setCorpo(sf::RectangleShape *c) {
    pCorpo = c;
    tamanho = pCorpo->getSize();
}

void Animacao::setAnimacao(string nome) {
    texturaAtual = nome;
    pCorpo->setTexture(&texturas[texturaAtual]);
}

void Animacao::animar(bool dir) {
    if (tempoAnimacao == 12) {
        tempoAnimacao = 0;
        frame++;
        if (frame >= 2)
            frame = 0;
    }
    if (dir)
        pCorpo->setTextureRect({(int)(frame * pCorpo->getSize().x + pCorpo->getSize().x), 0,
            (int)-pCorpo->getSize().x, (int)pCorpo->getSize().y});
    else
        pCorpo->setTextureRect({(int)(frame * pCorpo->getSize().x), 0,
            (int)pCorpo->getSize().x, (int)pCorpo->getSize().y});
    tempoAnimacao++;
}

