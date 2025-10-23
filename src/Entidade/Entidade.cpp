#include "../../includes/Entidade/Entidade.h"

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

    void Entidade::setPosicao(sf::Vector2f posicao) {
        pos = posicao;
        corpo.setPosition(pos);
    }

    const sf::Vector2f Entidade::getTamanho() const {
        return tam;
    }


    const sf::RectangleShape* Entidade::getCorpo() const {
        return &corpo;
    }

    void Entidade::desenhar() {
        pGGrafico->desenhaElemento(corpo);
    }

}