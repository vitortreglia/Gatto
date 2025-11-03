#ifndef TEXTO_H
#define TEXTO_H
#include <SFML/Graphics/Text.hpp>
#include "Ente.h"


namespace Entidade {
    class Texto : public Ente{
    private:
        sf::Text texto;
        sf::Font fonte;
    public:
        Texto(std::string conteudo, int tamanho, float x, float y);
        void setTexto(std::string txt);
        void desenhar();
        void executar();
    };
}


#endif //TEXTO_H
