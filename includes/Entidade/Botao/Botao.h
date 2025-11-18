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
        void setPosicao(sf::Vector2f pos);
        void setTamanho(sf::Vector2f tam);
        void executar();
    };
}


#endif //BOTAO_H
