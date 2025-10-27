#include "../../includes/Entidade/Entidade.h"
#include <vector>
#include <iostream>
namespace Entidade {
    Entidade::Entidade(sf::Vector2f tamanho, sf::Vector2f posicao):
    Ente(IDs::IDs::jogador),
    corpo(tamanho) {
        tam = tamanho;
        setPosicao(posicao);
        corpo.setFillColor(sf::Color::Blue);
    }

    Entidade::~Entidade() {
        setPosicao(sf::Vector2f(0.0f, 0.0f));
    }

    const sf::Vector2f Entidade::getPosicao() const {
        return corpo.getPosition();
    }


    void Entidade::setPosicao(sf::Vector2f posicao) {
        pos = posicao;
        corpo.setPosition(pos);
    }

    void Entidade::setTamanho(sf::Vector2f tamanho) {
        tam = tamanho;
        corpo.setSize(tam);
    }


    const sf::Vector2f Entidade::getTamanho() const {
        return tam;
    }

    std::vector<sf::Vector2f> Entidade::getCoordenadas() {
        std::vector<sf::Vector2f> coordenadas(4);
        std::vector<int> oi = {1, 2, 3, 4};
        for (int i = 0; i < 4; i++) {
            sf::Vector2f c = corpo.getTransform().transformPoint(corpo.getPoint(i));
            coordenadas[i].x = c.x;
            coordenadas[i].y = c.y;
        }
        return coordenadas;
    }


    void Entidade::desenhar() {
        pGGrafico->desenhaElemento(corpo);
    }

    void Entidade::colisao(sf::Vector2f colisao) {

    }

    void Entidade::atualizar() {
        desenhar();
    }

}