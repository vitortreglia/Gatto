#ifndef GAIVOTA_H
#define GAIVOTA_H

#include "EstadoRasante.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Itens/ArmaInimigo.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
        class EstadoGaivota;

            class Gaivota : public Inimigo {
            private:
                float tempo;
                float amplitude;
                float velocidadeHorizontal;
                float frequencia;
                float baseY;
                int direcao;

                EstadoGaivota* estado;

                float raioPercepcaoX;
                float raioPercepcaoY;
                float raioAtaque;
                float velocidadeAtaque;
                float velocidadeRasante;

                sf::Vector2f alvoAtaque;
                bool possuiPeixe;

                Itens::ArmaInimigo* pArma;

                //void fazerRasante(float dt, const sf::Vector2f& posJog);
                //void virarPara(const sf::Vector2f& posJog);

            public:
                Gaivota(float x, float y);
                ~Gaivota();

                //void verificaVidas();
                //void mover();
                Jogador* getJogador();
                sf::RectangleShape* getCorpo();
                void verificaVidas();
                void executar();
                void setEstado(EstadoGaivota* pEstado);
                bool patrulhar(float dt);
                bool fazerAtaque(float dt);
                //void pegarPeixe();
            };
        }
    }
}

#endif