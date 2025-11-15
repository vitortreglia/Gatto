#include "Entidade/Botao/Botao.h"
namespace Entidade {
    Botao::Botao(string rotulo):
    Entidade({500.0f, 100.0f}, 390, 100, IDs::Ente_IDs::Botao),
    textoBotao(rotulo, 42, 600.0f, 140.0f)
    {
        textura.setTextura("Data/Imagens/botao.png");
        textoBotao.setFonte("Data/Fontes/Barriecito-Regular.ttf");
        textoBotao.setCor(242, 237, 203, 255);
        setTextura(&textura);
    }

    Botao::~Botao() {

    }

    void Botao::setPosicao(sf::Vector2f pos) {
        Entidade::setPosicao(pos);
        sf::FloatRect b = textoBotao.getDimensoesTexto();
        float x = getPosicao().x + (getTamanho().x / 2) - (b.width / 2);
        float y = getPosicao().y + (getTamanho().y / 2) - (b.height);
        cout << x << y << endl;
        textoBotao.setPosicao(x, y);
    }

    void Botao::setTamanho(sf::Vector2f tam) {
        Entidade::setTamanho(tam);
    }

    void Botao::desenhar() {
        pGGrafico->desenharUI(&corpo);
    }

    void Botao::executar() {
        desenhar();
        textoBotao.executar();
    }
}