#ifndef GERENCIADORCOLISOES_H
#define GERENCIADORCOLISOES_H
#include <list>
#include "Lista/ListaEntidades.h"
#include <vector>
#include <utility>
#include "Entidade/Itens/Peixe.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

using namespace std;
namespace Gerenciador {
    class GerenciadorColisoes {
    private:
        Lista::ListaEntidades* pListaPersonagens;
        list<Entidade::Obstaculo::Obstaculo*> LOs;
        vector<Entidade::Personagem::Inimigo::Inimigo*> LIs;
        Entidade::Personagem::Jogador* pJogador1;
        vector<Entidade::Itens::Arma*> LHs;
        vector<Entidade::Itens::Peixe*> LPs;
    public:
        GerenciadorColisoes(Lista::ListaEntidades* pLPersonagens);
        ~GerenciadorColisoes();
        void addObstaculo(Entidade::Obstaculo::Obstaculo* obs);
        void addJogador(Entidade::Personagem::Jogador* pJog);
        void addInimigo(Entidade::Personagem::Inimigo::Inimigo* pIni);
        void addHitBox(Entidade::Itens::Arma* pH);
        void addPeixe(Entidade::Itens::Peixe* pPeixe);
        sf::Vector2f calculaNormal(const sf::Vector2f& vertice1, const sf::Vector2f& vertice2);
        vector<pair<float, float>> calculaProjecao(const vector<sf::Vector2f>& vertices, const vector<sf::Vector2f>& normal);
        sf::Vector2f calculaSobreposicao(vector<sf::Vector2f> coordCorpo1, vector<sf::Vector2f> coordCorpo2);
        sf::Vector2f verificarColisao(Entidade::Entidade* corpo1, Entidade::Entidade* corpo2);
        void tratarColisoesJogsObstacs();
        void tratarColisoesJogsInimigs();
        void tratarColisoesInimigsObstacs();
        void tratarColisoesAtaque();
        void tratarColisoesEventos();
        void executar();
    };
}


#endif //GERENCIADORCOLISOES_H
