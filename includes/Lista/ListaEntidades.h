#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H
#include "Lista.h"
#include "Entidade/Entidade.h"

/*  ListaEntidades
 *
 *      Implementacao com base no grupo de slides 10 parte A e B do Prof. Dr. Jean M. Simão
 *      da disciplina Tecnicas de Programacao. Material disponivel em
 *      https://pessoal.dainf.ct.utfpr.edu.br/jeansimao/Fundamentos2/LinguagemC++UML/Fundamentos2-LinguagemC++.htm
 *
 */

namespace Lista {
    class ListaEntidades {
    private:
        Lista<Entidade::Entidade> LEs;
    public:
        ListaEntidades();
        ~ListaEntidades();
        void incluir(Entidade::Entidade* pEntidade);
        void percorrer();
        void apagarEntidade(Entidade::Entidade* pEntidade);
        void apagarEntidade(unsigned int pos);
        unsigned int getTam() const;
        void limparLista();
        Entidade::Entidade* operator[](unsigned int pos);
    };
}

#endif //LISTAENTIDADES_H
