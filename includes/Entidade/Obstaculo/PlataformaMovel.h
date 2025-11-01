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
            PlataformaMovel(sf::Vector2f tam, float x, float y, float totalMovimento);
            ~PlataformaMovel();
            void mover();
            void executar();
            void obstaculizar();
        };
    }
}


#endif //PLATAFORMAMOVEL_H
