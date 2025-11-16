#ifndef ESTADOJOGO_H
#define ESTADOJOGO_H
#include "Estado.h"
#include "Fase/Fase.h"


namespace Estados {
    class EstadoJogo : public Estado{
    private:
        static EstadoJogo* pEstadoJogo;
        Fase::Fase* pFase;
        Entidade::Personagem::Jogador* pJog1;
        Entidade::Personagem::Jogador* pJog2;
        int arg[3];
    private:
        EstadoJogo();
    public:
        static EstadoJogo* getEstadoJogo(void* args);
        void iniciar(void* args);
        void sair(void* args);
        void tratarEventos();
        void atualizar();
        void desenhar();
    };
}


#endif //ESTADOJOGO_H
