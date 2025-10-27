#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "Entidade/Entidade.h"

namespace Entidade {
    namespace Obstaculo {
        class Obstaculo : public Entidade {
        protected:
            bool danoso;
        public:
            Obstaculo();
            ~Obstaculo();

            virtual void colisao();
        };
    }
}
#endif //OBSTACULO_H
