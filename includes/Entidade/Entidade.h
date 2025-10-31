#ifndef ENTIDADE_H
#define ENTIDADE_H
#include "../Ente.h"


namespace Entidade {
    class Entidade : public Ente {
    protected:
        sf::RectangleShape corpo;
        float x, y;
        sf::Vector2f tam;
    public:
        Entidade(sf::Vector2f tamanho = {50.0f, 50.0f}, float posx = 50.0f, float posy = 50.0f);
        virtual ~Entidade();
        void setPosicao(sf::Vector2f posicao);
        const sf::Vector2f getPosicao() const;
        void setTamanho(sf::Vector2f tamanho);
        const sf::Vector2f getTamanho() const;
        std::vector<sf::Vector2f> getCoordenadas();
        virtual void desenhar();
        virtual void executar() = 0;
        virtual void colisao(sf::Vector2f colisao);
    };
}


#endif //ENTIDADE_H
