#ifndef PLATAFORMAMOVEL_H
#define PLATAFORMAMOVEL_H
#include "Obstaculo.h"


namespace Entidade {
    namespace Obstaculo {
        class PlataformaMovel : public Obstaculo {
        private:
            float movimentoMax;
            float somaMovimento;
            float tempoMax;
            float somaTempo;
            bool direcao;

        public:
            PlataformaMovel(float x = 100, float y = 100, bool direcao = false);
            ~PlataformaMovel();
            void mover();
            void executar();
            void obstaculizar(Personagem::Jogador* pJog);
        };
    }
}


#endif //PLATAFORMAMOVEL_H
