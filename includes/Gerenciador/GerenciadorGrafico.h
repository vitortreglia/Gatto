#ifndef GERENCIADORGRAFICO_H
#define GERENCIADORGRAFICO_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define TELA_X 800.0f
#define TELA_Y 600.0f

using namespace std;

namespace Gerenciador {
    class GerenciadorGrafico {
    private:
        sf::RenderWindow* window;
        static GerenciadorGrafico* pGGrafico;
    private:
        GerenciadorGrafico();
    public:
        ~GerenciadorGrafico();
        const bool verificaJanelaAberta();
        GerenciadorGrafico* getGerenciadorGrafico();
        sf::RenderWindow* getWindow() const;
        void desenhaElemento(sf::RectangleShape corpo);
        void mostraElementos();
        void fecharJanela();
        void limpaJanela();
    };
}

#endif //GERENCIADORGRAFICO_H
