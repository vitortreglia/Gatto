#include "Entidade/Obstaculo/PlataformaGiratoria.h"

namespace Entidade {
    namespace Obstaculo {
        PlataformaGiratoria::PlataformaGiratoria(sf::Vector2f tam, float x, float y, float velGiro):
        Obstaculo(false, tam, x, y),
        velocidadeGiro(velGiro),
        angulo(0.0001f),
        tempoMax(3.0f),
        somaTempo(0.0f)
        {
            posInicial = {x, y};
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
                angulo += velocidadeGiro * tempoFrame;
                girar();
            }
            if (somaTempo > tempoMax) {
                angulo = 0.0f;
                somaTempo = 0.0f;
            }


        }

        void PlataformaGiratoria::executar() {
            obstaculizar();
            desenhar();
        }

    }
}