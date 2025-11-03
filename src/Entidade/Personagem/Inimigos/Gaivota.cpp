#include "Entidade/Personagem/Inimigos/Gaivota.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "IDs.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigos {
            Gaivota::Gaivota(float x, float y) {

                setPosicao(sf::Vector2f(x, y));
                baseY = y;

                setTamanho(sf::Vector2f(80.0, 50.0));

                tempo = 0.0;
                amplitude = 30.0;
                velocidadeHorizontal = 120.0;
                frequencia = 5.0;

                numVidas = 2;
                vivo = true;
                corpo.setFillColor(sf::Color::White);
                //id = IDs::IDs::InimigoGaivota
            }

            Gaivota::~Gaivota(){}

            void Gaivota::verificaVidas() {
                if (numVidas <= 0)
                    vivo = false;
            }

            void Gaivota::mover() {

                const float dt = 0.016f;
                tempo += dt;

                sf::Vector2f pos = getPosicao();
                pos.x += velocidadeHorizontal * dt;
                pos.y = baseY + std::sin(tempo * frequencia) * amplitude;

                setPosicao(pos);
                corpo.setPosition(pos);
            }

            void Gaivota::executar() {

                mover();
                verificaVidas();
                desenhar();
            }
        }
    }
}