#ifndef FASECIDADE_H
#define FASECIDADE_H
#include "Fase.h"
#include "Entidade/Itens/Projetil.h"
#include "Entidade/Personagem/Inimigo/Cachorro.h"

namespace Fase {
    class FaseCidade : public Fase {
    private:
        const int maxRoseiras;
        const int maxChefoes;
        int numInimChefao;
        int numRoseira;
    public:
        FaseCidade(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2);
        ~FaseCidade();
    protected:
        void criarProjetil(float x, float y, bool direita,
                   Entidade::Personagem::Inimigo::Cachorro* pCachorro);
        void criarChefao(float x, float y);
        void criarRoseira(float x, float y, bool danoso);
        void criarInimigos(multimap<char, sf::Vector2f> inimigos);
        void criarObstaculos(multimap<char, sf::Vector2f> obstaculos);
    };
}


#endif //FASECIDADE_H
