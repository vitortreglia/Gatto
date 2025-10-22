#include "GerenciadorGrafico.h"
//#include "../Entidade/Personagem/Jogador/Jogador.h"
#ifndef GERENCIADOREVENTOS_H
#define GERENCIADOREVENTOS_H

namespace Gerenciador {
    class GerenciadorEvento {
    private:
        GerenciadorGrafico* pGGrafico;
        //Entidade::Personagem::Jogador::Jogador* pJogador;
        static GerenciadorEvento* pGEvento;
    private:
        GerenciadorEvento();
    public:
        ~GerenciadorEvento();
        static GerenciadorEvento* getGerenciadorEvento();
        //void setJogador(Entidade::Personagem::Jogador::Jogador* pJ);
        //void verificaTeclaPressionada(sf::Keyboard::Key tecla);
        //void verificaTeclaSolta(sf::Keyboard::Key tecla);
        //void executar();
    };
}

#endif //GERENCIADOREVENTOS_H
