#include "Entidade/Entidade.h"
#include <vector>
#include <iostream>
namespace Entidade {
    float Entidade::tempoFrame(0.0f);

    Entidade::Entidade(sf::Vector2f tamanho, float posx, float posy):
    Ente(&corpo),
    x(posx),
    y(posy),
    tam(tamanho),
    corpo(tam),
    ativo(true),
    buffer(nullptr),
    entrada(nullptr)
    {
        setPosicao(sf::Vector2f(x, y));
        //corpo.setFillColor(sf::Color::Blue);
        textura.setCorpo(&corpo);
    }

    Entidade::~Entidade() {
        setPosicao(sf::Vector2f(0.0f, 0.0f));
    }

    const bool Entidade::estaAtivo() const {
        return ativo;
    }

    void Entidade::setAtivo(bool at) {
        ativo = at;
    }

    const sf::Vector2f Entidade::getPosicao() const {
        return corpo.getPosition();
    }

    void Entidade::setPosicao(sf::Vector2f posicao) {
        x = posicao.x;
        y = posicao.y;
        corpo.setPosition(x, y);
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
        for (int i = 0; i < 4; i++) {
            sf::Vector2f c = corpo.getTransform().transformPoint(corpo.getPoint(i));
            coordenadas[i].x = c.x;
            coordenadas[i].y = c.y;
        }
        return coordenadas;
    }

    void Entidade::getTempoFrame() {
        tempoFrame = pGGrafico->getTempo();
    }

    void Entidade::lerDataBuffer() {
        string ani;
        int frame;
        int TA;
        entrada >> ID >>ativo >> ani >> frame >> TA >> x >> y;
        setPosicao({x, y});
        textura.setAnimacao(ani);
        textura.setFrame(frame);
        textura.setTAnimacao(TA);
    }

    void Entidade::salvarDataBuffer() {
        buffer << ID << ' ' << ativo << ' ' << textura.getAnimacao() << ' ' << textura.getFrame() << ' '
        << textura.getTAnimacao() << ' ' << x << ' ' << y << ' ';
    }

}