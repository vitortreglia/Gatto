#ifndef FASE_H
#define FASE_H
#include "Gerenciador/GerenciadorColisoes.h"
#include "Lista/ListaEntidades.h"
#include <fstream>
#include <string>

namespace Fase {
    class Fase : public Ente {
    protected:
        Lista::ListaEntidades listaEnt;
        Gerenciador::GerenciadorColisoes* pGColisoes;
        sf::RectangleShape fundo;
        sf::FloatRect limitesFase;
    public:
        Fase(IDs::Ente_IDs id);
        ~Fase();
        void executar();
        sf::FloatRect getLimitesFase();
    protected:
        void criarFase();
        void criarPlataforma(float x, float y);
        void criarPeixe(float x, float y);
        void criarInimigoRato(float x, float y);
        void criarProjetil(float x, float y, bool direita);
        void criarCenario();
        void atualizarEntidades();
        //virtual void criarObstaculo() = 0;
    public:
        void inscreverObservadores();
        void desinscreverObservadores();
    };
}
#endif //FASE_H
