#ifndef ENTIDADE_H
#define ENTIDADE_H
#include "Ente.h"


namespace Entidade {
    class Entidade : public Ente {
    protected:
        sf::Vector2f tam;
        sf::RectangleShape corpo;
        float x, y;
        static float tempoFrame;
        bool ativo;
    public:
        Entidade(sf::Vector2f tamanho = {50.0f, 50.0f}, float posx = 50.0f, float posy = 50.0f, IDs::IDs id = IDs::IDs::vazio);
        virtual ~Entidade();
        const bool estaAtivo();
        void setAtivo(bool at);
        void setPosicao(sf::Vector2f posicao);
        const sf::Vector2f getPosicao() const;
        void setTamanho(sf::Vector2f tamanho);
        const sf::Vector2f getTamanho() const;
        vector<sf::Vector2f> getCoordenadas();
        static void getTempoFrame();
        virtual void executar() = 0;
    };
}


#endif //ENTIDADE_H
