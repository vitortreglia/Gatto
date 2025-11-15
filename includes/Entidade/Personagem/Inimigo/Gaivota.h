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
                static Jogador* pJog1;
                static Jogador* pJog2;
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

                //void fazerRasante(float dt, const sf::Vector2f& posJog);
                //void virarPara(const sf::Vector2f& posJog);

            public:
                Gaivota(float x, float y);
                ~Gaivota();
                static void setJogadores(Jogador* pJ1, Jogador* pJ2);
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