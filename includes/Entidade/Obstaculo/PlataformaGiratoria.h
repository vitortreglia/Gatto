#ifndef PLATAFORMAGIRATORIA_H
#define PLATAFORMAGIRATORIA_H
#include "Obstaculo.h"


namespace Entidade {
    namespace Obstaculo {
        class PlataformaGiratoria : public Obstaculo {
        private:
            float velocidadeGiro;
            float angulo;
            float tempoMax;
            float somaTempo;
            sf::Vector2f posInicial;
        public:
            PlataformaGiratoria(float x, float y);
            ~PlataformaGiratoria();
            void girar();
            void executar();
            void obstaculizar();
        };
    }
}

#endif //PLATAFORMAGIRATORIA_H
