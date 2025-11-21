#ifndef PLATAFORMAGIRATORIA_H
#define PLATAFORMAGIRATORIA_H
#include "Obstaculo.h"


namespace Entidade {
    namespace Obstaculo {
        class GiraGira : public Obstaculo {
        private:
            const float velocidadeGiro;
            float angulo;
            const float tempoMax;
            float somaTempo;
            const sf::Vector2f posInicial;
        public:
            GiraGira(float x, float y);
            ~GiraGira();
            void girar();
            void executar();
            void obstaculizar(Personagem::Jogador* pJog);
            void lerDataBuffer();
            void carregar(istream &entrada);
            void salvarDataBuffer();
            void salvar(ostream &saida);
        };
    }
}

#endif //PLATAFORMAGIRATORIA_H
