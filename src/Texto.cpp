#include "Texto.h"


    Texto::Texto(std::string conteudo, int tamanho, float x, float y):
    Ente(IDs::Ente_IDs::Texto, &texto)
    {
        fonte.loadFromFile("Data/Fontes/Roboto-Medium.ttf");
        texto.setString(conteudo);
        texto.setCharacterSize(tamanho);
        texto.setPosition(x, y);
        texto.setColor(sf::Color::Black);
        texto.setFont(fonte);
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

    void Texto::executar() {
        desenhar();
    }


