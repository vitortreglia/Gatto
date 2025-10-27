#ifndef GERENCIADORCOLISOES_H
#define GERENCIADORCOLISOES_H
#include "Lista/ListaEntidades.h"
#include <vector>
#include <utility>
#include <cmath>

using namespace std;
namespace Gerenciador {
    class GerenciadorColisoes {
    private:
        Lista::ListaEntidades* pListaPersonagens;
    public:
        GerenciadorColisoes(Lista::ListaEntidades* pLPersonagens);
        ~GerenciadorColisoes();
        sf::Vector2f calculaNormal(const sf::Vector2f& vertice1, const sf::Vector2f& vertice2);
        vector<pair<float, float>> calculaProjecao(const vector<sf::Vector2f>& vertices, const vector<sf::Vector2f>& normal);
        float calcularColisao(Entidade::Entidade* corpo1, Entidade::Entidade* corpo2);
        void executar();
    };
}


#endif //GERENCIADORCOLISOES_H
