#ifndef FASE_H
#define FASE_H
#include "Gerenciador/GerenciadorColisoes.h"
#include "Lista/ListaEntidades.h"
#include <fstream>
#include <string>

namespace Fase {
    class Fase {
    protected:
        Lista::ListaEntidades listaEnt;
        Gerenciador::GerenciadorColisoes* pGColisoes;
        sf::FloatRect limitesFase;
    public:
        Fase();
        ~Fase();
        void executar();
        sf::FloatRect getLimitesFase();
    protected:
        void criarFase();
        void criarPlataforma(float x, float y);
        void criarPeixe(float x, float y);
        void criarRato(float x, float y);
        void criarProjetil(float x, float y, bool direita);
        void criarCenario();
        void atualizarEntidades();
        //virtual void criarObstaculo() = 0;
    };
}
#endif //FASE_H
