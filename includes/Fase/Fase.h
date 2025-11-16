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
        const int numFase;
        const int maxPMovel;
        const int maxInimGaivota;
        int numInimGaivota;
        int numPMovel;
    public:
        Fase(string caminhoTextura, int nFase);
        ~Fase();
        virtual void executar();
        sf::FloatRect getLimitesFase();
        const int getFase() const;
    protected:
        void semearRand();
        void criarPlataforma(float x, float y);
        void criarPlataformaMovel(float x, float y, bool direcao);
        void criarPeixe(float x, float y);
        void criarInimigoGaivota(float x, float y);
        virtual void criarObstaculos() = 0;
        virtual void criarInimigos() = 0;
        void criarCenario();
        void atualizarEntidades();
    };
}
#endif //FASE_H
