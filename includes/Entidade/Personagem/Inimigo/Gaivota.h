#ifndef GAIVOTA_H
#define GAIVOTA_H

#include "EstadoRasante.h"
#include "Entidade/Personagem/Ataque.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"


namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
        class EstadoGaivota;

            class Gaivota : public Inimigo {
            public:
                Ataque ataque;
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
                string imgGaivota;

            public:
                Gaivota(float x, float y);
                ~Gaivota();
                //void verificaVidas();
                void danificar(Jogador *pJ);
                void mover();
                void executar();
                void setEstado(EstadoGaivota* pEstado);
                Jogador* patrulhar(float dt);
            };
        }
    }
}

#endif