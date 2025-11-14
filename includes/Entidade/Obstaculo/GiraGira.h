#ifndef PLATAFORMAGIRATORIA_H
#define PLATAFORMAGIRATORIA_H
#include "Obstaculo.h"


namespace Entidade {
    namespace Obstaculo {
        class GiraGira : public Obstaculo {
        private:
            float velocidadeGiro;
            float angulo;
            float tempoMax;
            float somaTempo;
            sf::Vector2f posInicial;
        public:
            GiraGira(float x, float y);
            ~GiraGira();
            void girar();
            void executar();
            void obstaculizar();
        };
    }
}

#endif //PLATAFORMAGIRATORIA_H
