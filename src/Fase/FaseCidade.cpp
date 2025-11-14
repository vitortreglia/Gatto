#include "Fase/FaseCidade.h"

namespace Fase {
    FaseCidade::FaseCidade(Entidade::Personagem::Jogador *pJog1, Entidade::Personagem::Jogador *pJog2):
    Fase(IDs::Ente_IDs::FaseCidade),
    maxChefoes(5),
    maxInimGaivota(8)
    {

    }

    FaseCidade::~FaseCidade() {

    }

    void FaseCidade::criarProjetil(float x, float y, bool direita) {
        if (direita) {
            x += 80.0f;
        }
        Entidade::Entidade* objEntidade = new Entidade::Itens::Projetil(x, y, direita);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirProjetil(static_cast<Entidade::Itens::Projetil*>(objEntidade));
        }
    }

    void FaseCidade::criarChefao(float x, float y) {

    }

    void FaseCidade::criarRoseira(float x, float y) {

    }

}