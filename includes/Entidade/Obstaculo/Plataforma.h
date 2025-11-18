#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Plataforma : public Obstaculo {
        public:
            Plataforma(float x, float y, int fase);
            ~Plataforma();
            string imgFaseJardim;
            string imgFaseCidade;
            void executar();
            void obstaculizar(Personagem::Jogador* pJog);
        };
    }
}




#endif //PLATAFORMA_H
