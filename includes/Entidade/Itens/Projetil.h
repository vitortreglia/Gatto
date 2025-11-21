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
            Projetil();
            ~Projetil();
            void setDirecao(bool dir);
            void mover();
            void executar();
            void lerDataBuffer();
            void carregar(istream &entrada);
            void salvarDataBuffer();
            void salvar(ostream& saida);
        };
    }
}


#endif //PROJETIL_H
