#ifndef PROJETIL_H
#define PROJETIL_H
#include "Entidade/Entidade.h"


namespace Entidade {
    namespace Itens {
        class Projetil : public Entidade{
        private:
            float tempoLancamento;
            bool direita;
        public:
            Projetil(float x, float y, bool direita);
            ~Projetil();
            void mover();
            void colisao(sf::Vector2f colisao, Entidade *pEntidade);
            void executar();
        };
    }
}


#endif //PROJETIL_H
