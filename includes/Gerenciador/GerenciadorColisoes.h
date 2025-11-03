#ifndef GERENCIADORCOLISOES_H
#define GERENCIADORCOLISOES_H
#include <list>
#include "Lista/ListaEntidades.h"
#include <vector>
#include <utility>
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Entidade/Personagem/Inimigos/Inimigo.h"

using namespace std;
namespace Gerenciador {
    class GerenciadorColisoes {
    private:
        Lista::ListaEntidades* pListaPersonagens;
        list<Entidade::Obstaculo::Obstaculo*> LOs;
        Entidade::Personagem::Jogador* pJogador1;
        std::vector<Entidade::Personagem::Inimigos::Inimigo*> LIs;
    public:
        GerenciadorColisoes(Lista::ListaEntidades* pLPersonagens);
        ~GerenciadorColisoes();
        void addObstaculo(Entidade::Obstaculo::Obstaculo* obs);
        void addJogador(Entidade::Personagem::Jogador* pJog);
        void addInimigo(Entidade::Personagem::Inimigos::Inimigo* ini);
        sf::Vector2f calculaNormal(const sf::Vector2f& vertice1, const sf::Vector2f& vertice2);
        vector<pair<float, float>> calculaProjecao(const vector<sf::Vector2f>& vertices, const vector<sf::Vector2f>& normal);
        sf::Vector2f calculaSobreposicao(vector<sf::Vector2f> coordCorpo1, vector<sf::Vector2f> coordCorpo2);
        sf::Vector2f verificarColisao(Entidade::Entidade* corpo1, Entidade::Entidade* corpo2);
        void tratarColisoesJogsObstacs();
        void executar();
    };
}


#endif //GERENCIADORCOLISOES_H
