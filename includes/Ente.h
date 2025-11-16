#ifndef ENTE_H
#define ENTE_H
#include "Gerenciador/GerenciadorGrafico.h"
using namespace std;

class Ente {
protected:
    int ID; //identificacao do ente
    static Gerenciador::GerenciadorGrafico* pGGrafico;
    sf::RectangleShape* pFig;
    sf::Text* pTxt;
    static int nID;
public:
    Ente(sf::RectangleShape* pF);
    Ente(sf::Text* pT);
    virtual ~Ente();
    const int getId() const;
    void desenhar();
    virtual void executar() = 0;
};



#endif //ENTE_H
