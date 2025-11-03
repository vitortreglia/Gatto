#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "IDs.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Gaivota::Gaivota(float x, float y):
            Inimigo(120.0f, {80.0f, 50.0f},x, y, 2, IDs::IDs::InimigoGaivota),
            baseY(y),
            amplitude(30.0f),
            frequencia(5.0f),
            tempoMovimento(0.0f)
            {
                baseY = y;
                andar(true);
                corpo.setFillColor(sf::Color::White);
                setVoador(true);
            }

            Gaivota::~Gaivota(){}

            /*void Gaivota::verificaVidas() {
                if (numVidas <= 0) {
                    vivo = false;
                    ativo = false;
                }
            }*/

            void Gaivota::mover() {
                atualizarPos();
                const float dt = 0.016f;
                tempoMovimento += dt;
                sf::Vector2f pos = getPosicao();
                pos.y = baseY + std::sin(tempoMovimento * frequencia) * amplitude;
                atualizarPos(pos);
            }

            void Gaivota::executar() {
                mover();
                verificaVidas();
                desenhar();
            }
        }
    }
}