#ifndef ENTIDADE_H
#define ENTIDADE_H
#include "../Ente.h"

namespace Entidade {
    class Entidade : public Ente {
    protected:
        sf::RectangleShape corpo;
        sf::Vector2f pos;
        sf::Vector2f tam;
    public:
        Entidade(sf::Vector2f tamanho = sf::Vector2f(50.0f, 50.0f), sf::Vector2f posicao = sf::Vector2f(50.0f, 50.0f));
        virtual ~Entidade();
        const sf::RectangleShape* getCorpo() const;
        void setPosicao(sf::Vector2f posicao);
        const sf::Vector2f getPosicao() const;
        const sf::Vector2f getTamanho() const;
        virtual void desenhar();
        virtual void atualizar() = 0;
    };
}


#endif //ENTIDADE_H
