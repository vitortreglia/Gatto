#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Obstaculo/Obstaculo.h"

namespace Entidade {
        class Chao : public Entidade {
        private:
            int nFase;
        public:
            Chao(float x, float y, int fase);
            ~Chao();
            string imgFaseJardim;
            string imgFaseCidade;
            void executar();
            void obstaculizar(Personagem::Jogador* pJog);
            void lerDataBuffer();
            void carregar(istream &entrada);
            void salvarDataBuffer();
            void salvar(ostream &saida);
        };
}




#endif //PLATAFORMA_H
