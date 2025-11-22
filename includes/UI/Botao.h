#ifndef BOTAO_H
#define BOTAO_H
#include "Texto.h"

class Botao : public Ente {
    private:
        Texto textoBotao;
        sf::RectangleShape corpo;
    public:
        Botao(string rotulo);
        ~Botao();
        void moverBotao(sf::Vector2f pos);
        void destacar();
        void tirarDestaque();
        void executar();
        sf::FloatRect getCoordBotao();
    };


#endif //BOTAO_H
