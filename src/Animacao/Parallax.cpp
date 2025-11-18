#include "Animacao/Parallax.h"

Parallax::Parallax(int offX, int offY, float escala):
movimentoFundo(0.0f),
movimentoMeio(0.3f),
movimentoFrente(0.8f){
    offsetX = offX;
    offsetY = offY;
    spriteFundo.setScale(escala, escala);
    spriteMeio.setScale(escala, escala);
    spriteFrente.setScale(escala, escala);
}

Parallax::~Parallax() {

}

void Parallax::setTexturas(std::string tFundo, std::string tMeio, std::string tFrente) {
    fundo.loadFromFile(tFundo);
    fundo.setRepeated(true);
    spriteFundo.setTexture(fundo);
    //spriteFundo.setScale(0.5, 0.5);
    if (tMeio != "") {
        spriteMeio.setColor(sf::Color::White);
        meio.loadFromFile(tMeio);
        meio.setRepeated(true);
        spriteMeio.setTexture(meio);
    } else {
        spriteMeio.setColor(sf::Color::Transparent);
    }
    if (tFrente != "") {
        spriteFrente.setColor(sf::Color::White);
        frente.loadFromFile(tFrente);
        frente.setRepeated(true);
        spriteFrente.setTexture(frente);
    } else {
        spriteFrente.setColor(sf::Color::Transparent);
    }
}

void Parallax::setMovimento(float mFundo, float mMeio, float mFrente) {
    movimentoFundo = mFundo;
    movimentoMeio = mMeio;
    movimentoFrente = mFrente;
}

void Parallax::deslocar(float x, float y) {
    spriteFundo.setPosition(x - offsetX, y - offsetY);
    spriteFundo.setTextureRect({(int)(x * movimentoFundo), (int)(y * movimentoFundo), offsetX * 2, offsetY * 2});
    spriteMeio.setPosition(x - offsetX, y - offsetY);
    spriteMeio.setTextureRect({(int)(x * movimentoMeio), 0, offsetX * 2, offsetY * 2});
    spriteFrente.setPosition(x - offsetX, y - offsetY);
    spriteFrente.setTextureRect({(int)(x * movimentoFrente), (int)(y * movimentoFrente), offsetX * 2, offsetY * 2});
}

sf::Sprite *Parallax::getFundo() {
    return &spriteFundo;
}

sf::Sprite *Parallax::getMeio() {
    return &spriteMeio;
}

sf::Sprite *Parallax::getFrente() {
    return &spriteFrente;
}
