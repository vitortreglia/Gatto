#include "Entidade/Botao/Botao.h"
namespace Entidade {
    Botao::Botao(string rotulo):
    Entidade({500.0f, 100.0f}, 390, 100),
    textoBotao(rotulo, 42, 600.0f, 140.0f)
    {
        //textura.setTextura("Data/Imagens/botao.png");
        textoBotao.setFonte("Data/Fontes/KirangHaerang-Regular.ttf");
        textoBotao.setCor(242, 237, 203, 255);
        //setTextura(&textura);
        corpo.setFillColor({63, 61, 61, 255});
    }

    Botao::~Botao() {

    }

    void Botao::setPosicao(sf::Vector2f pos) {
        Entidade::setPosicao(pos);
        sf::FloatRect b = textoBotao.getDimensoesTexto();
        float x = getPosicao().x + (getTamanho().x / 2) - (b.width / 2);
        float y = getPosicao().y + (getTamanho().y / 2) - (b.height);
        textoBotao.setPosicao(x, y);
    }

    void Botao::setTamanho(sf::Vector2f tam) {
        Entidade::setTamanho(tam);
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