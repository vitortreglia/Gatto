#ifndef BOTAO_H
#define BOTAO_H
#include "Texto.h"
#include "Entidade/Entidade.h"

namespace Entidade {
    class Botao : public Entidade::Entidade {
    private:
        Texto textoBotao;
    public:
        Botao(string rotulo);
        ~Botao();
        void desenhar();
        void executar();
    };
}


#endif //BOTAO_H
