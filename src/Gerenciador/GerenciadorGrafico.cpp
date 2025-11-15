#include "Gerenciador/GerenciadorGrafico.h"

namespace Gerenciador {
    GerenciadorGrafico* GerenciadorGrafico::pGGrafico(nullptr);

    GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Gatto")),
    camera({0, 0, TELA_X, TELA_Y}),
    viewP1({0, 0, TELA_X/2, TELA_Y}),
    viewP2({0, 0, TELA_X/2, TELA_Y}),
    limitesCamera({0.0f, 0.0f, 0.0f, 0.0f}),
    cameraX(TELA_X/2),
    cameraY(TELA_Y/2),
    tempo(0.0f),
    multiplayer(false)
    {
        if (window == nullptr) {
            cout << "Nao foi possivel criar a janela grafica" << endl;
            exit(1);
        }
        uiBuffer.create(1280, 720);
        window->setFramerateLimit(60);
        //camera.setCenter(TELA_X/2, TELA_Y/2);
        viewP1.setViewport({0, 0, 0.5f, 1.0f});
        viewP1.zoom(1.5f);
        viewP2.setViewport({0.5f, 0, 0.5f, 1.0f});
        viewP2.zoom(1.5f);
        window->setView(camera);
    }

    GerenciadorGrafico::~GerenciadorGrafico() {
        if (window) {
            delete(window);
            window = nullptr;
        }
    }

    void GerenciadorGrafico::setMultiplayer(bool mult) {
        multiplayer = mult;
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

    void GerenciadorGrafico::setFundo(Animacao *fundo) {
        fundo->getTextura()->setSmooth(true);
        this->fundo.setTexture(*fundo->getTextura());
        this->fundo.setScale(1.1f, 1.1f);
    }

    void GerenciadorGrafico::desenharEnte(sf::RectangleShape* corpo) {
        if (multiplayer) {
            window->setView(viewP1);
            window->draw(*corpo);
            window->setView(viewP2);
            window->draw(*corpo);
        } else {
            window->setView(camera);
            window->draw(*corpo);
        }
    }

    void GerenciadorGrafico::desenharUI(sf::RectangleShape* corpo) {
        uiBuffer.draw(*corpo);
        uiBuffer.display();
    }

    void GerenciadorGrafico::desenharUI(sf::Text* texto) {
        uiBuffer.draw(*texto);
        uiBuffer.display();
    }

    void GerenciadorGrafico::mostraElementos() {
        uiSprite.setTexture(uiBuffer.getTexture());
        window->setView(window->getDefaultView());
        window->draw(uiSprite);
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
        uiBuffer.clear(sf::Color::Transparent);
        window->clear();
        window->setView(camera);
        window->draw(fundo);
    }

    float GerenciadorGrafico::getTempo() {
        return tempo;
    }

    void GerenciadorGrafico::resetaRelogio() {
        tempo = relogio.getElapsedTime().asSeconds();
        relogio.restart();
    }

    void GerenciadorGrafico::moveCamera(sf::Vector2f coord, int jog) {
        if (multiplayer) {
            if (jog == 1) {
                viewP1X += 5 * (coord.x - viewP1X) * tempo;

                if (viewP1X < limitesCamera.left + TELA_X / 4) {
                    viewP1X = TELA_X/4;
                } else if (viewP1X > limitesCamera.width - TELA_X / 4) {
                    viewP1X = limitesCamera.width - TELA_X / 4;
                }
                if (coord.y < viewP1Y - 180 || coord.y > viewP1Y + 180)
                    viewP1Y = coord.y;
                else if (coord.y < viewP1Y - 100 || coord.y > viewP1Y + 100)
                    viewP1Y += 3 * (coord.y - viewP1Y) * tempo;
                if (viewP1Y < limitesCamera.top + TELA_Y / 2) {
                    viewP1Y = limitesCamera.top + TELA_Y / 2;
                } else if (viewP1Y > limitesCamera.height - TELA_Y / 2) {
                    viewP1Y = limitesCamera.height - TELA_Y / 2;
                }
                viewP1.setCenter(viewP1X, viewP1Y);
                fundo.setPosition(viewP1X - TELA_X / 2, viewP1Y - TELA_Y);
                window->setView(viewP1);
                window->draw(fundo);

            } else {
                viewP2X += 5 * (coord.x - viewP2X) * tempo;

                if (viewP2X < limitesCamera.left + TELA_X / 4) {
                    viewP2X = TELA_X/4;
                } else if (viewP2X > limitesCamera.width - TELA_X / 4) {
                    viewP2X = limitesCamera.width - TELA_X / 4;
                }
                if (coord.y < viewP2Y - 360 || coord.y > viewP2Y + 360)
                    viewP2Y = coord.y;
                else if (coord.y < viewP2Y - 100 || coord.y > viewP2Y + 100)
                    viewP2Y += 3 * (coord.y - viewP2Y) * tempo;
                if (viewP2Y < limitesCamera.top + TELA_Y / 2) {
                    viewP2Y = limitesCamera.top + TELA_Y / 2;
                } else if (viewP2Y > limitesCamera.height - TELA_Y / 2) {
                    viewP2Y = limitesCamera.height - TELA_Y / 2;
                }
                viewP2.setCenter(viewP2X, viewP2Y);
                fundo.setPosition(viewP2X - TELA_X / 2, viewP2Y - TELA_Y);
                window->setView(viewP2);
                window->draw(fundo);

            }
        } else {
            cameraX += 5 * (coord.x - cameraX) * tempo;

            if (cameraX < limitesCamera.left + TELA_X / 2) {
                cameraX = TELA_X/2;
            } else if (cameraX > limitesCamera.width - TELA_X / 2) {
                cameraX = limitesCamera.width - TELA_X / 2;
            }
            if (coord.y < cameraY - 360 || coord.y > cameraY + 360)
                cameraY = coord.y;
            else if (coord.y < cameraY - 100 || coord.y > cameraY + 100)
                cameraY += 3 * (coord.y - cameraY) * tempo;
            if (cameraY < limitesCamera.top + TELA_Y / 2) {
                cameraY = limitesCamera.top + TELA_Y / 2;
            } else if (cameraY > limitesCamera.height - TELA_Y / 2) {
                cameraY = limitesCamera.height - TELA_Y / 2;
            }
            camera.setCenter(cameraX, cameraY);
            fundo.setPosition(cameraX - TELA_X / 2, cameraY - 100 - TELA_Y / 2);
            window->setView(camera);

        }


    }

    void GerenciadorGrafico::setLimitesCamera(sf::FloatRect limites) {
        limitesCamera = limites;
    }

    sf::FloatRect GerenciadorGrafico::getLimitesCamera() {
        return limitesCamera;
    }


}


