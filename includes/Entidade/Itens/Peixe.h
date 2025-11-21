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
            void executar();
            void lerDataBuffer();
            void carregar(istream &entrada);
            void salvarDataBuffer();
            void salvar(ostream& saida);
        };
    }
}

#endif //PEIXE_H
