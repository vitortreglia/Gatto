#include "Texto.h"


    Texto::Texto(std::string conteudo, int tamanho, float x, float y):
    Ente(&texto)
    {
        fonte.loadFromFile("Data/Fontes/RubikBubbles-Regular.ttf");
        texto.setString(conteudo);
        texto.setCharacterSize(tamanho);
        texto.setPosition(x, y);
        texto.setFont(fonte);
        texto.setColor({120, 99, 27, 255});
        texto.setOutlineThickness(10);
        texto.setOutlineColor({231, 211, 41, 255});
    }

    Texto::~Texto() {}

    void Texto::setTexto(std::string txt) {
        texto.setString(txt);
    }

    void Texto::setTamanho(int tam) {
        texto.setCharacterSize(tam);
    }

    void Texto::setPosicao(float x, float y) {
        texto.setPosition(x, y);
    }

    void Texto::setFonte(string caminho) {
        fonte.loadFromFile(caminho);
        texto.setFont(fonte);
    }

    void Texto::setCor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a) {
        texto.setColor({r, g, b, a});
        texto.setOutlineThickness(0);
    }

    sf::FloatRect Texto::getDimensoesTexto() {
        return texto.getGlobalBounds();
    }

    void Texto::executar() {
        desenhar();
    }


