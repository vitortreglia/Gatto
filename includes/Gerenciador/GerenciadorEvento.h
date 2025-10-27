#ifndef GERENCIADOREVENTOS_H
#define GERENCIADOREVENTOS_H

#include "GerenciadorGrafico.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
namespace Gerenciador {
    class GerenciadorEvento {
    private:
        GerenciadorGrafico* pGGrafico;
        static Entidade::Personagem::Jogador* pJogador;
        static GerenciadorEvento* pGEvento;
    private:
        GerenciadorEvento();
    public:
        ~GerenciadorEvento();
        static GerenciadorEvento* getGerenciadorEvento();
        static void setJogador(Entidade::Personagem::Jogador* pJ);
        void verificaTeclaPressionada();
        void verificaTeclaSolta();
        void executar();
    };
}

#endif //GERENCIADOREVENTOS_H
