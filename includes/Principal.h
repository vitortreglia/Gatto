#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Gerenciador/GerenciadorGrafico.h"


class Principal {
private:
    Gerenciador::GerenciadorGrafico* pGGrafico;
public:
    Principal();
    ~Principal();
    void executar();
};



#endif //PRINCIPAL_H
