#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Ente_IDs.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Gaivota::Gaivota(float x, float y):
            Inimigo(1, 120.0f, {80.0f, 50.0f},x, y, 2, IDs::Ente_IDs::InimigoGaivota),
            baseY(y),
            amplitude(3.0f),
            frequencia(5.0f),
            tempoMovimento(0.0f)
            {
                andar(true);
                corpo.setFillColor(sf::Color::White);
                setVoador(true);
            }

            Gaivota::~Gaivota(){}

            void Gaivota::danificar(Jogador *pJ) {
                nivelMaldade++;

            }

            void Gaivota::mover() {
                deslocamento.y = std::sin(tempoMovimento * frequencia) * amplitude;
                atualizarPos();
                tempoMovimento += tempoFrame;
                if (tempoMovimento > 4.0f) {
                    parar();
                    andar(!direita);
                    tempoMovimento = 0.0f;
                }
            }

            void Gaivota::executar() {
                mover();
                verificaVidas();
                desenhar();
            }
        }
    }
}