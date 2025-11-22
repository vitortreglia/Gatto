#ifndef GERENCIADORGRAFICO_H
#define GERENCIADORGRAFICO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>

#include "Animacao/Animacao.h"
#include "Animacao/Parallax.h"

#define TELA_X 1280.0f
#define TELA_Y 720.0f

using namespace std;

/*  Gerenciador Grafico feito usando o Padrao de Projeto Singleton
 *
 *      Implementacao de elementos da classe baseada no material disponibilizado
 *      pelo então monitor Giovane Limas Salvi, no 2º semestre de 2022 em
 *      https://www.youtube.com/watch?v=gfGE5KY1OQU e
 *      https://github.com/Giovanenero/JogoPlataforma2D-Jungle/tree/main
 *
 */

namespace Gerenciador {
    class GerenciadorGrafico {
    private:
        sf::RenderWindow* window;
        sf::View camera;
        sf::View viewP1;
        sf::View viewP2;
        sf::RenderTexture uiBuffer;
        Parallax background1P;
        Parallax background2P;
        sf::Sprite uiSprite;
        sf::Clock relogio;
        float tempo;
        static GerenciadorGrafico* pGGrafico;
        float cameraX, viewP1X, viewP2X;
        float cameraY, viewP1Y, viewP2Y;
        bool multiplayer;
        sf::FloatRect limitesCamera;
    private:
        GerenciadorGrafico();
    public:
        ~GerenciadorGrafico();
        void setMultiplayer(bool mult);
        const bool verificaJanelaAberta();
        static GerenciadorGrafico* getGerenciadorGrafico();
        sf::RenderWindow* getWindow() const;
        void setFundo(string fundo, string meio, string frente);
        void setMovimentoFundo(float fundo, float meio, float frente);
        void desenharEnte(sf::RectangleShape* corpo);
        void desenharUI(sf::RectangleShape* corpo);
        void desenharUI(sf::Text* texto);
        void mostraElementos();
        void fecharJanela();
        void limpaJanela();
        float getTempo();
        void resetaRelogio();
        void moveCamera(sf::Vector2f coord, int jog);
        void setLimitesCamera(sf::FloatRect limites);
        sf::FloatRect getLimitesCamera();
    };
}

#endif //GERENCIADORGRAFICO_H
