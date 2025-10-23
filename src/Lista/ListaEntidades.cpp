#include "Lista/ListaEntidades.h"

namespace Lista {
    ListaEntidades::ListaEntidades():
    LEs()
    {}

    ListaEntidades::~ListaEntidades() {
        limparLista();
    }

    void ListaEntidades::addEntidade(Entidade::Entidade *pEntidade) {
        LEs.novoElemento(pEntidade);
    }

    void ListaEntidades::apagarEntidade(Entidade::Entidade *pEntidade) {
        LEs.apagarElemento(pEntidade);
    }

    void ListaEntidades::apagarEntidade(unsigned int pos) {
        LEs.apagarElemento(pos);
    }

    unsigned int ListaEntidades::getTam() const {
        return LEs.getTam();
    }

    void ListaEntidades::limparLista() {
        LEs.limparLista();
    }
    Entidade::Entidade *ListaEntidades::operator[](unsigned int pos) {
        return LEs.operator[](pos);
    }

}