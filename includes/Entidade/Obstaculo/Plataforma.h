#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Plataforma : public Obstaculo {
        public:
            Plataforma(float x, float y);
            ~Plataforma();
            void executar();
            void obstaculizar();
        };
    }
}




#endif //PLATAFORMA_H
