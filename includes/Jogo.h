#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Fase/Fase.h"
#include "Fase/FaseJardim.h"
#include "Gerenciador/GerenciadorEstados.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Gerenciador/GerenciadorGrafico.h"


class Jogo {
private:
    Gerenciador::GerenciadorEvento* pGEvento;
    Gerenciador::GerenciadorGrafico* pGGrafico;
    Gerenciador::GerenciadorEstados* pGEstados;
public:
    Jogo();
    ~Jogo();
    void executar();
};



#endif //PRINCIPAL_H
