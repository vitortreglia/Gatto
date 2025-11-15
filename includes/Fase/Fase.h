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
        Animacao texturaFundo;
        sf::FloatRect limitesFase;
        int numFase;
        const int maxPMovel;
        const int maxInimGaivota;
        int numInimGaivota;
        int numPMovel;
    public:
        Fase(IDs::Ente_IDs id, string caminhoTextura, int nFase);
        ~Fase();
        void executar();
        sf::FloatRect getLimitesFase();
        int getFase();
    protected:
        int semearRand();
        void criarPlataforma(float x, float y);
        void criarPlataformaMovel(float x, float y, bool direcao);
        void criarPeixe(float x, float y);
        void criarInimigoGaivota(float x, float y);
        //void criarCenario();
        void atualizarEntidades();
        //virtual void criarObstaculo() = 0;
    };
}
#endif //FASE_H
