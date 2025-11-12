#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Fase/Fase.h"
#include "Fase/FaseJardim.h"
#include "Gerenciador/GerenciadorEstados.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Gerenciador/GerenciadorGrafico.h"


class Principal {
private:
    Gerenciador::GerenciadorEvento* pGEvento;
    Gerenciador::GerenciadorGrafico* pGGrafico;
    Gerenciador::GerenciadorEstados* pGEstados;
public:
    Principal();
    ~Principal();
    void executar();
};



#endif //PRINCIPAL_H
