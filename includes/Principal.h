#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Gerenciador/GerenciadorGrafico.h"


class Principal {
private:
    Gerenciador::GerenciadorGrafico* pGGrafico;
    Gerenciador::GerenciadorEvento* pGEvento;
    Entidade::Personagem::Jogador jog;
public:
    Principal();
    ~Principal();
    void executar();
};



#endif //PRINCIPAL_H
