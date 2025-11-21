#include "Entidade/Obstaculo/GiraGira.h"

namespace Entidade {
    namespace Obstaculo {
        GiraGira::GiraGira(float x, float y):
        Obstaculo(false, sf::Vector2f(200, 50), x, y),
        velocidadeGiro(2),
        angulo(0.0f),
        tempoMax(3.0f),
        somaTempo(0.0f),
        posInicial({x, y})
        {
            textura.inserirTextura("base", "Data/Imagens/placeholder.png");
            textura.setAnimacao("base");
        }

        GiraGira::~GiraGira() {}

        void GiraGira::girar() {
            float px = posInicial.x + tam.x / 2 + (tam.x / 2) * -cos(angulo * (M_PI / 180)) - (tam.y / 2) * -sin(angulo * (M_PI / 180));
            float py = posInicial.y + (tam.x / 2) * -sin(angulo * (M_PI / 180)) + (tam.y / 2) * -cos(angulo * (M_PI / 180));
            setPosicao(sf::Vector2f(px, py));
            corpo.setRotation(angulo);
        }

        void GiraGira::obstaculizar(Personagem::Jogador* pJog) {
            
        }

        void GiraGira::executar() {
            //obstaculizar();
            //desenhar();
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

        void GiraGira::lerDataBuffer() {
            Obstaculo::lerDataBuffer();
            entrada >> somaTempo >> angulo >> posInicial.x >> posInicial.y;
            girar();
        }

        void GiraGira::carregar(istream &entrada) {
            this->entrada.rdbuf(entrada.rdbuf());
            lerDataBuffer();
        }

        void GiraGira::salvarDataBuffer() {
            buffer << "giragira ";
            Obstaculo::salvarDataBuffer();
            buffer << somaTempo << ' ' << angulo << ' ' << posInicial.x << ' ' << posInicial.y << endl;
        }

        void GiraGira::salvar(ostream &saida) {
            buffer.rdbuf(saida.rdbuf());
            salvarDataBuffer();
        }

    }
}