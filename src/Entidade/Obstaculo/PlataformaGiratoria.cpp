#include "Entidade/Obstaculo/PlataformaGiratoria.h"

namespace Entidade {
    namespace Obstaculo {
        PlataformaGiratoria::PlataformaGiratoria(float x, float y):
        Obstaculo(false, sf::Vector2f(200, 50), x, y, IDs::IDs::PlataformaGiratoria),
        velocidadeGiro(2),
        angulo(0.0f),
        tempoMax(3.0f),
        somaTempo(0.0f)
        {
            posInicial = {x, y};
            corpo.setFillColor(sf::Color::Magenta);
        }

        PlataformaGiratoria::~PlataformaGiratoria() {}

        void PlataformaGiratoria::girar() {
            float px = posInicial.x + (tam.x / 2) * -cos(angulo * (M_PI / 180)) - (tam.y / 2) * -sin(angulo * (M_PI / 180));
            float py = posInicial.y + (tam.x / 2) * -sin(angulo * (M_PI / 180)) + (tam.y / 2) * -cos(angulo * (M_PI / 180));
            setPosicao(sf::Vector2f(px, py));
            corpo.setRotation(angulo);
        }

        void PlataformaGiratoria::obstaculizar() {
            somaTempo += tempoFrame;
            if (angulo < 180.0f) {
                angulo += velocidadeGiro;
                girar();
            }
            if (somaTempo > tempoMax) {
                angulo = 0.0f;
                somaTempo = 0.0f;
            }
        }

        void PlataformaGiratoria::executar() {
            obstaculizar();
            //desenhar();
        }

    }
}