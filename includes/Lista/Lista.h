#ifndef LISTA_H
#define LISTA_H

/*  Template Lista
 *
 *      Implementacao com base no grupo de slides 10 parte A e B do Prof. Dr. Jean M. Simão
 *      da disciplina Tecnicas de Programacao. Material disponivel em
 *      https://pessoal.dainf.ct.utfpr.edu.br/jeansimao/Fundamentos2/LinguagemC++UML/Fundamentos2-LinguagemC++.htm
 *
 */

namespace Lista {
    template<class TL>
    class Lista {
    private:
        class Elemento {
        private:
            Elemento* pProx;
            TL* pInfo;
        public:
            Elemento();
            ~Elemento();
            void incluir(TL* pElem);
            TL* getElemento();
            void setProx(Elemento* pProximo);
            Elemento* getProx();
        };
        Elemento* pPrimeiro;
        Elemento* pUltimo;
        unsigned int tam;
    public:
        Lista();
        ~Lista();
        void incluir(TL* pElem);
        void apagarElemento(TL* pElem);
        void apagarElemento(unsigned int pos);
        unsigned int getTam() const;
        void limpar();
        TL* operator[](unsigned int pos);
    };

    template<class TL>
    Lista<TL>::Elemento::Elemento():
    pInfo(nullptr),
    pProx(nullptr)
    {}

    template<class TL>
    Lista<TL>::Elemento::~Elemento() {}

    template<class TL>
    void Lista<TL>::Elemento::incluir(TL* pElem) {
        pInfo = pElem;
    }

    template<class TL>
    TL* Lista<TL>::Elemento::getElemento() {
        return pInfo;
    }

    template<class TL>
    void Lista<TL>::Elemento::setProx(Elemento* pProximo) {
        pProx = pProximo;
    }

    template<class TL>
    typename Lista<TL>::Elemento* Lista<TL>::Elemento::getProx() {
        return pProx;
    }

    template<class TL>
    Lista<TL>::Lista():
    pPrimeiro(nullptr),
    pUltimo(nullptr),
    tam(0)
    {}

    template<class TL>
    Lista<TL>::~Lista() {
        Lista<TL>::limpar();
    }

    template<class TL>
    void Lista<TL>::incluir(TL *pElem) {
        if (pElem) {
            if (!pPrimeiro) {
                pPrimeiro = new Elemento();
                if (pPrimeiro) {
                    pPrimeiro->incluir(pElem);
                    pUltimo = pPrimeiro;
                    tam++;
                }
            } else {
                Elemento* aux = new Elemento();
                aux->incluir(pElem);
                pUltimo->setProx(aux);
                pUltimo = aux;
                tam++;
            }
        }
    }

    template<class TL>
    void Lista<TL>::apagarElemento(TL *pElem) {
        if (pElem) {
            Elemento* anterior = nullptr;
            Elemento* atual = pPrimeiro;
            while (atual != nullptr && atual->getElemento() != pElem) {
                anterior = atual;
                atual = anterior->getProx();
            }
            if (atual->getElemento() == pElem) {
                anterior->setProx(atual->getProx());
                delete atual;
                tam--;
            }
        }
    }

    template<class TL>
    void Lista<TL>::apagarElemento(unsigned int pos) {
        if (pos < tam) {
            if (pos == 0) {
                Elemento* aux = pPrimeiro;
                pPrimeiro = pPrimeiro->getProx();
                delete aux;
                tam--;
            } else {
                Elemento* anterior = nullptr;
                Elemento* atual = pPrimeiro;
                for (unsigned int i = 1; i <= pos; i++) {
                    anterior = atual;
                    atual = anterior->getProx();
                }
                if (pos < tam - 1) {
                    anterior->setProx(atual->getProx());
                    delete atual;
                    tam--;
                } else {
                    anterior->setProx(nullptr);
                    pUltimo = anterior;
                    delete atual;
                    tam--;
                }
            }
        }
    }

    template<class TL>
    unsigned int Lista<TL>::getTam() const {
        return tam;
    }

    template<class TL>
    void Lista<TL>::limpar() {
        Elemento* aux1 = nullptr;
        Elemento* aux2 = pPrimeiro;
        while (aux2) {
            aux1 = aux2;
            aux2 = aux1->getProx();
            if (aux1) {
                //delete (aux1->getElemento());
                delete aux1;
            }
        }
        pPrimeiro = nullptr;
        pUltimo = nullptr;
        tam = 0;
    }

    template<class TL>
    TL *Lista<TL>::operator[](unsigned int pos) {
        if (pos < tam) {
            Elemento* aux = pPrimeiro;
            for (unsigned int i = 1; i <= pos; i++) {
                aux = aux->getProx();
            }
            return aux->getElemento();
        }
        return nullptr;
    }

}
#endif //LISTA_H
