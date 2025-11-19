#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Obstaculo/Obstaculo.h"

namespace Entidade {
        class Chao : public Entidade {
        public:
            Chao(float x, float y, int fase);
            ~Chao();
            string imgFaseJardim;
            string imgFaseCidade;
            void executar();
            void obstaculizar(Personagem::Jogador* pJog);
        };
}




#endif //PLATAFORMA_H
