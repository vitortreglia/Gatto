#ifndef FASE_H
#define FASE_H
#include "Gerenciador/GerenciadorColisoes.h"
#include "Lista/ListaEntidades.h"

namespace Fase {
    class Fase {
    protected:
        Lista::ListaEntidades listaPersonagens;
        Gerenciador::GerenciadorColisoes* pGColisoes;
    public:
        Fase();
        ~Fase();
        void criarFase();
        void executar();
    };
}
#endif //FASE_H
