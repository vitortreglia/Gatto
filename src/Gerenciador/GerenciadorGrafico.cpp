#include "Gerenciador/GerenciadorGrafico.h"

namespace Gerenciador {

    GerenciadorGrafico* GerenciadorGrafico::pGGrafico(nullptr);

    GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Gatto")),
    camera(sf::FloatRect(0, 0, 1280, 720)),
    limitesCamera({0.0f, 0.0f, 3300.0f, 2000.0f}),
    cameraX(TELA_X/2),
    cameraY(TELA_Y/2)
    {
        if (window == nullptr) {
            cout << "Nao foi possivel criar a janela grafica" << endl;
            exit(1);
        }
        camera.setCenter(TELA_X/2, TELA_Y/2);
        window->setView(camera);
    }

    GerenciadorGrafico::~GerenciadorGrafico() {
        if (window) {
            delete(window);
            window = nullptr;
        }
    }

    GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
        if (!pGGrafico) {
            pGGrafico = new GerenciadorGrafico();
        }
        return pGGrafico;
    }

    sf::RenderWindow* GerenciadorGrafico::getWindow() const {
        return window;
    }

    void GerenciadorGrafico::desenharEnte(sf::RectangleShape corpo) {
        window->draw(corpo);
    }

    void GerenciadorGrafico::mostraElementos() {
        window->display();
    }

    const bool GerenciadorGrafico::verificaJanelaAberta() {
        if (window->isOpen())
            return true;
        return false;
    }

    void GerenciadorGrafico::fecharJanela() {
        window->close();
    }

    void GerenciadorGrafico::limpaJanela() {
        window->clear();
    }

    float GerenciadorGrafico::getTempo() {
        return tempo;
    }

    void GerenciadorGrafico::resetaRelogio() {
        tempo = relogio.getElapsedTime().asSeconds();
        relogio.restart();
    }

    void GerenciadorGrafico::moveCamera(float x, float y) {
        cameraX += 5 * (x - cameraX) * tempo;

        if (cameraX < limitesCamera.left + TELA_X / 2) {
            cameraX = TELA_X/2;
        } else if (cameraX > limitesCamera.width - TELA_X / 2) {
            cameraX = limitesCamera.width - TELA_X / 2;
        }
        if (y < cameraY - 100 || y > cameraY + 100)
            cameraY += 3 * (y - cameraY) * tempo;
        if (cameraY < limitesCamera.top + TELA_Y / 2) {
            cameraY = limitesCamera.top + TELA_Y / 2;
        } else if (cameraY > limitesCamera.height - TELA_Y / 2) {
            cameraY = limitesCamera.height - TELA_Y / 2;
        }

        camera.setCenter(cameraX, cameraY);

        window->setView(camera);
    }

    void GerenciadorGrafico::setLimitesCamera(sf::FloatRect limites) {
        limitesCamera = limites;
    }



}


