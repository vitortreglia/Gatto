#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Fase/Fase.h"
#include "Fase/FaseJardim.h"
#include "Gerenciador/GerenciadorEstados.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Gerenciador/GerenciadorGrafico.h"


class Principal {
private:
    Gerenciador::GerenciadorGrafico* pGGrafico;
    Gerenciador::GerenciadorEvento* pGEvento;
    Gerenciador::GerenciadorEstados* pGEstados;
public:
    Principal();
    ~Principal();
    void executar();
};



#endif //PRINCIPAL_H
