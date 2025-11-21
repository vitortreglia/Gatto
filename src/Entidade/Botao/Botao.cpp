#include "Entidade/Botao/Botao.h"
namespace Entidade {
    Botao::Botao(string rotulo):
    Ente(&corpo),
    textoBotao(rotulo, 42, 600.0f, 140.0f),
    corpo({400, 80})
    {
        //textura.setTextura("Data/Imagens/botao.png");
        textoBotao.setFonte("Data/Fontes/KirangHaerang-Regular.ttf");
        textoBotao.setCor(242, 237, 203, 255);
        //setTextura(&textura);
        corpo.setFillColor({63, 61, 61, 255});
    }

    Botao::~Botao() {

    }

    void Botao::moverBotao(sf::Vector2f pos) {
        corpo.setPosition(pos);
        sf::FloatRect b = textoBotao.getDimensoesTexto();
        float x = corpo.getPosition().x + (corpo.getSize().x / 2) - (b.width / 2);
        float y = corpo.getPosition().y + (corpo.getSize().y / 2) - (b.height);
        textoBotao.setPosicao(x, y);
    }

    void Botao::destacar() {
        corpo.setOutlineColor(sf::Color::White);
        corpo.setOutlineThickness(5);
    }

    void Botao::tirarDestaque() {
        corpo.setOutlineThickness(0);
    }

    void Botao::executar() {
        pGGrafico->desenharUI(&corpo);
        textoBotao.executar();
    }
}