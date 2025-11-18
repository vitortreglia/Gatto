#ifndef ANIMACAO_H
#define ANIMACAO_H
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace std;

class Animacao {
private:
    map<string, sf::Texture> texturas;
    sf::RectangleShape* pCorpo;
    sf::Vector2f tamanho;
    int tempoAnimacao;
    int frame;
    string texturaAtual;
public:
    Animacao();
    ~Animacao();
    void inserirTextura(string nome, string caminho);
    void setCorpo(sf::RectangleShape* c);
    void setAnimacao(string nome);
    void animar(bool dir);
};



#endif //ANIMACAO_H
