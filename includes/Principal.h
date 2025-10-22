#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Gerenciador/GerenciadorGrafico.h"


class Principal {
private:
    Gerenciador::GerenciadorGrafico* pGGrafico;
    Jogador::Jogador jogador;
public:
    Principal();
    ~Principal();
    void executar();
};



#endif //PRINCIPAL_H
