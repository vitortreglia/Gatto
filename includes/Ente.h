#ifndef ENTE_H
#define ENTE_H
#include "Ente_IDs.h"
#include "Gerenciador/GerenciadorGrafico.h"
using namespace std;

class Ente {
protected:
    IDs::Ente_IDs ID; //identificacao do ente
    static Gerenciador::GerenciadorGrafico* pGGrafico;
    sf::RectangleShape* pFig;
    sf::Text* pTxt;
public:
    Ente(IDs::Ente_IDs id, sf::RectangleShape* pF);
    Ente(IDs::Ente_IDs id, sf::Text* pT);
    virtual ~Ente();
    const IDs::Ente_IDs getId() const;
    virtual void desenhar();
    virtual void executar() = 0;
};



#endif //ENTE_H
