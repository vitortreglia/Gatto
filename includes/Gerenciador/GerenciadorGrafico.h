#ifndef GERENCIADORGRAFICO_H
#define GERENCIADORGRAFICO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>

#define TELA_X 1280.0f
#define TELA_Y 720.0f

using namespace std;

namespace Gerenciador {
    class GerenciadorGrafico {
    private:
        sf::RenderWindow* window;
        sf::View camera;
        sf::RenderTexture uiBuffer;
        sf::Sprite uiSprite;
        sf::Clock relogio;
        float tempo;
        static GerenciadorGrafico* pGGrafico;
        float cameraX;
        float cameraY;
        sf::FloatRect limitesCamera;
    private:
        GerenciadorGrafico();
    public:
        ~GerenciadorGrafico();
        const bool verificaJanelaAberta();
        static GerenciadorGrafico* getGerenciadorGrafico();
        sf::RenderWindow* getWindow() const;
        void desenharEnte(sf::RectangleShape* corpo);
        void desenharTexto(sf::Text texto);
        void mostraElementos();
        void fecharJanela();
        void limpaJanela();
        float getTempo();
        void resetaRelogio();
        void moveCamera(float x, float y);
        void setLimitesCamera(sf::FloatRect limites);
        sf::FloatRect getLimitesCamera();
    };
}

#endif //GERENCIADORGRAFICO_H
