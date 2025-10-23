#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H
#include "Lista.h"
#include "Entidade/Entidade.h"

namespace Lista {
    class ListaEntidades {
    private:
        Lista<Entidade::Entidade> LEs;
    public:
        ListaEntidades();
        ~ListaEntidades();
        void addEntidade(Entidade::Entidade* pEntidade);
        void apagarEntidade(Entidade::Entidade* pEntidade);
        void apagarEntidade(unsigned int pos);
        unsigned int getTam() const;
        void limparLista();
        Entidade::Entidade* operator[](unsigned int pos);
    };
}

#endif //LISTAENTIDADES_H
