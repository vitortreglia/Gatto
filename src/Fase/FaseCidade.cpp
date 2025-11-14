#include "Fase/FaseCidade.h"

namespace Fase {
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
}