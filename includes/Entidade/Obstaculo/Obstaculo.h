    #ifndef OBSTACULO_H
#define OBSTACULO_H
#include "Entidade/Entidade.h"

namespace Entidade {
    namespace Obstaculo {
        class Obstaculo : public Entidade {
        protected:
            bool danoso;
        public:
            Obstaculo(bool dano, sf::Vector2f tamanho, float x, float y, IDs::IDs id);
            ~Obstaculo();
            virtual void obstaculizar() = 0;
            virtual void executar() = 0;
            virtual void colisao();
        };
    }
}
#endif //OBSTACULO_H
