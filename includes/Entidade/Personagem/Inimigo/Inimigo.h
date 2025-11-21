#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        class Jogador;

        namespace Inimigo {
            class Inimigo : public Personagem {
            protected:
                int nivelMaldade;
                static Jogador* pJog1;
                static Jogador* pJog2;
                Jogador* pUltimoAtacante;
            public:
                Inimigo(int nMaldade, float vel, sf:: Vector2f tam, float px, float py, int vidas);
                ~Inimigo();
                static void setJogadores(Jogador* pJ1, Jogador* pJ2);
                void setUltimoAtacante(Jogador* pJ);
                void verificaVidas();
                void lerDataBuffer();
                virtual void carregar(istream &entrada) = 0;
                void salvarDataBuffer();
                virtual void salvar(ostream& saida) = 0;
                virtual void danificar(Jogador* pJ) = 0;
                virtual void mover() = 0;
                virtual void executar() = 0;
            };
        }
    }
}


#endif //INIMIGO_H
