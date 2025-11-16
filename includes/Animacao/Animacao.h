#ifndef ANIMACAO_H
#define ANIMACAO_H
#include <SFML/Graphics/Texture.hpp>


class Animacao {
private:
    sf::Texture textura;
public:
    Animacao();
    ~Animacao();
    void setTextura(std::string caminho);
    sf::Texture* getTextura();
};



#endif //ANIMACAO_H
