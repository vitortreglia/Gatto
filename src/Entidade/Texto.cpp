#include "Entidade/Texto.h"

namespace Entidade {
    Texto::Texto(std::string conteudo, int tamanho, float x, float y):
    Ente(IDs::Ente_IDs::Texto, nullptr)
    {
        fonte.loadFromFile("Data/Fontes/Roboto-Medium.ttf");
        texto.setString(conteudo);
        texto.setCharacterSize(tamanho);
        texto.setPosition(x, y);
        texto.setColor(sf::Color::White);
        texto.setFont(fonte);
    }

    Texto::~Texto() {}

    void Texto::setTexto(std::string txt) {
        texto.setString(txt);
    }


    void Texto::desenhar() {
        pGGrafico->desenharTexto(texto);
    }


    void Texto::executar() {
        desenhar();
    }


}