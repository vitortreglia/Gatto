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
                const float amplitude;
                const float frequencia;
                EstadoGaivota* estado;
                const float raioPercepcaoX;
                const float raioPercepcaoY;
                bool possuiPeixe;

            public:
                Gaivota(float x, float y);
                ~Gaivota();
                void danificar(Jogador *pJ);
                void mover();
                void executar();
                void setEstado(EstadoGaivota* pEstado);
                Jogador* patrulhar(float dt);
                void lerDataBuffer();
                void carregar(istream &entrada);
                void salvarDataBuffer();
                void salvar(ostream& saida);
            };
        }
    }
}

#endif