#ifndef FASE_H
#define FASE_H
#include "Gerenciador/GerenciadorColisoes.h"
#include "Lista/ListaEntidades.h"

namespace Fase {
    class Fase {
    protected:
        Lista::ListaEntidades listaEnt;
        Gerenciador::GerenciadorColisoes* pGColisoes;
    public:
        Fase();
        ~Fase();
        void executar();
    protected:
        void criarFase();
        void criarPlataformas();
        void criarCenario();
        //virtual void criarObstaculo() = 0;
    };
}
#endif //FASE_H
