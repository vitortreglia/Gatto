#include "../../includes/Entidade/Entidade.h"

namespace Entidade {
    Entidade::Entidade(sf::Vector2f tamanho, sf::Vector2f posicao):
    tam(tamanho),
    pos(posicao),
    corpo(tam) {
        corpo.setPosition(posicao);
    }

    Entidade::~Entidade() {}

    const sf::Vector2f Entidade::getPosicao() const {
        return pos;
    }

    void Entidade::setPosicao(sf::Vector2f posicao) {
        pos = posicao;
        corpo.setPosition(pos);
    }

    const sf::Vector2f Entidade::getTamanho() const {
        return tam;
    }

    void Entidade::setTamanho(sf::Vector2f tamanho) {
        tam = tamanho;
        corpo.setSize(tam);
    }

    const sf::RectangleShape* Entidade::getCorpo() const {
        return &corpo;
    }

    void Entidade::desenhar() {
        pGGrafico->desenhaElemento(corpo);
    }


}