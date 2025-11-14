#ifndef TEXTO_H
#define TEXTO_H
#include <SFML/Graphics/Text.hpp>
#include "Ente.h"



    class Texto : public Ente{
    private:
        sf::Text texto;
        sf::Font fonte;
    public:
        Texto(std::string conteudo, int tamanho, float x, float y);
        ~Texto();
        void setTexto(std::string txt);
        void setTamanho(int tam);
        void setPosicao(float x, float y);
        void executar();
    };



#endif //TEXTO_H
