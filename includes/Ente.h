#ifndef ENTE_H
#define ENTE_H
#include "IDs.h"
#include "Gerenciador/GerenciadorGrafico.h"
using namespace std;

class Ente {
protected:
    IDs::IDs ID; //identificacao do ente
    static Gerenciador::GerenciadorGrafico* pGGrafico;
    sf::RectangleShape* pFig;
public:
    Ente(IDs::IDs id, sf::RectangleShape* pF);
    virtual ~Ente();
    const IDs::IDs getId() const;
    void desenhar();
    virtual void executar() = 0;
};



#endif //ENTE_H
