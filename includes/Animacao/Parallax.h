#ifndef PARALLAX_H
#define PARALLAX_H
#include <SFML/Graphics.hpp>

/*  Parallax
 *
 *      Implementacao autoral com base em conhecimentos previos.
 *
 */

class Parallax {
private:
    sf::Texture fundo;
    sf::Texture meio;
    sf::Texture frente;
    sf::Sprite spriteFundo;
    sf::Sprite spriteMeio;
    sf::Sprite spriteFrente;
    float movimentoFundo;
    float movimentoMeio;
    float movimentoFrente;
    int offsetX;
    int offsetY;
public:
    Parallax(int offX, int offY, float escala);
    ~Parallax();
    void setMovimento(float mFundo, float mMeio, float mFrente);
    void setTexturas(std::string tFundo, std::string tMeio, std::string tFrente);
    void deslocar(float x, float y);
    sf::Sprite* getFundo();
    sf::Sprite* getMeio();
    sf::Sprite* getFrente();
};



#endif //PARALLAX_H
