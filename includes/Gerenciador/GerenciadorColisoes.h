#ifndef GERENCIADORCOLISOES_H
#define GERENCIADORCOLISOES_H
#include <list>
#include <set>
#include <vector>
#include <utility>

#include "Entidade/Chao.h"
#include "Lista/ListaEntidades.h"
#include "Entidade/Itens/Peixe.h"
#include "Entidade/Itens/Projetil.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

using namespace std;
namespace Gerenciador {
    class GerenciadorColisoes {
    private:
        Lista::ListaEntidades* pListaPersonagens;
        list<Entidade::Obstaculo::Obstaculo*> LOs;
        list<Entidade::Chao*> LCs;
        vector<Entidade::Personagem::Inimigo::Inimigo*> LIs;
        Entidade::Personagem::Jogador* pJogador1;
        Entidade::Personagem::Jogador* pJogador2;
        vector<Entidade::Itens::Peixe*> LPxs;
        set<Entidade::Itens::Projetil*> LPs;
    public:
        GerenciadorColisoes(Lista::ListaEntidades* pLPersonagens);
        ~GerenciadorColisoes();
        void incluirObstaculo(Entidade::Obstaculo::Obstaculo* obs);
        void incluirJogadores(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2);
        void incluirInimigo(Entidade::Personagem::Inimigo::Inimigo* pIni);
        void incluirPeixe(Entidade::Itens::Peixe* pPeixe);
        void incluirProjetil(Entidade::Itens::Projetil* pProjetil);
        void incluirChao(Entidade::Chao* pChao);
        sf::Vector2f calculaNormal(const sf::Vector2f& vertice1, const sf::Vector2f& vertice2);
        vector<pair<float, float>> calculaProjecao(const vector<sf::Vector2f>& vertices, const vector<sf::Vector2f>& normal);
        sf::Vector2f calculaSobreposicao(vector<sf::Vector2f> coordCorpo1, vector<sf::Vector2f> coordCorpo2);
        sf::Vector2f verificarColisao(Entidade::Entidade* corpo1, Entidade::Entidade* corpo2);
        void corrigirColisao(Entidade::Personagem::Personagem* pPersonagem, sf::Vector2f colisao);
        void tratarColisoesJogsObstacs();
        void tratarColisoesJogsInimigs();
        void tratarColisoesInimigsObstacs();
        void tratarColisoesEventos();
        void tratarColisoesProjeteis();
        void executar();
    };
}


#endif //GERENCIADORCOLISOES_H
