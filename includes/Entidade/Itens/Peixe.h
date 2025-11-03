#ifndef PEIXE_H
#define PEIXE_H
#include "Entidade/Entidade.h"


namespace Entidade {
    namespace Itens {
        class Peixe : public Entidade {
        private:
            float movimento;
            bool sentido;
        public:
            Peixe(float x, float y);
            ~Peixe();
            void mover();
            void colisao(sf::Vector2f colisao, Entidade *pEntidade);
            void executar();
        };
    }
}

#endif //PEIXE_H
