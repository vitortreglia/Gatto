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
        const int numFase;
        const int maxPMovel;
        const int maxInimGaivota;
        int numInimGaivota;
        int numPMovel;
        int numJogs;
        istream buffer;
    public:
        Fase(int nFase);
        ~Fase();
        virtual void executar();
        sf::FloatRect getLimitesFase();
        const int getFase() const;
        void salvar();
    protected:
        void semearRand();
        void criarChao(float x, float y);
        void criarPlataformaMovel(float x, float y, bool direcao);
        void criarPeixe(float x, float y);
        void criarInimigoGaivota(float x, float y);
        virtual void criarObstaculos(multimap<char, sf::Vector2f> obstaculos) = 0;
        virtual void criarInimigos(multimap<char, sf::Vector2f> inimigos) = 0;
        virtual void carregarFase() = 0;
        void criarCenario(string caminho);
        void atualizarEntidades();
    };
}
#endif //FASE_H
