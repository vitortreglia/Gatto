#ifndef GATTO_CACHORRO_H
#define GATTO_CACHORRO_H

#include "Entidade/Personagem/Ataque.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Itens/Projetil.h"

namespace Entidade {
        namespace Personagem {
            namespace Inimigo {
                class Cachorro : public Inimigo {
                public:
                    Ataque ataque;
                private:
                    float raioPercepcaoX;
                    float raioAtaque;
                    float velocidade;
                    float fatorFuria;
                    Itens::Projetil* pProjetil;
                    float tempoPatrulha;
                    int pID;

                public:
                    Cachorro(float x, float y);
                    ~Cachorro();
                    const int getProjetilID();
                    void mover();
                    void executar();
                    void danificar(Jogador *pJ);
                    void atualizaMaldade();
                    void patrulhar();

                    void perseguir();
                    void atirarOsso();
                    void setProjetil(Itens::Projetil* pProj);
                    void lerDataBuffer();
                    void carregar(istream &entrada);
                    void salvarDataBuffer();
                    virtual void salvar(ostream& saida);
                };
            }
        }
}

#endif //GATTO_CACHORRO_H