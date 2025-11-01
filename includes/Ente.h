#ifndef ENTE_H
#define ENTE_H
#include "IDs.h"
#include "Gerenciador/GerenciadorGrafico.h"
using namespace std;

class Ente {
protected:
    IDs::IDs ID; //identificacao do ente
    static Gerenciador::GerenciadorGrafico* pGGrafico;
public:
    Ente(IDs::IDs id);
    virtual ~Ente();
    const IDs::IDs getId() const;
    virtual void desenhar() = 0;
    virtual void executar() = 0;
};



#endif //ENTE_H
