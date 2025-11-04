#ifndef GAIVOTA_H
#define GAIVOTA_H

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Itens/ArmaInimigo.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {

            class Gaivota : public Inimigo {
            private:
                float tempo;
                float amplitude;
                float velocidadeHorizontal;
                float frequencia;
                float baseY;
                int direcao;

                int estado;
                float raioPercepcaoX;
                float raioPercepcaoY;
                float raioAtaque;
                float velocidadeAtaque;
                float velocidadeRasante;

                sf::Vector2f alvoAtaque;
                bool possuiPeixe;

                Itens::ArmaInimigo* pArma;
                void patrulhar(float dt);
                void fazerRasante(float dt, const sf::Vector2f& posJog);
                void fazerAtaque(float dt);
                void decidirEstado(const sf::Vector2f& posJog);
                void virarPara(const sf::Vector2f& posJog);

            public:
                Gaivota(float x, float y);
                ~Gaivota();

                //void verificaVidas();
                void mover();
                void verificaVidas();
                void executar();

                void setArma(Itens::ArmaInimigo* arma);
                void pegarPeixe();
            };
        }
    }
}

#endif