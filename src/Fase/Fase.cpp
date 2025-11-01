#include "Fase/Fase.h"

#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/Plataforma.h"
#include "Entidade/Obstaculo/PlataformaGiratoria.h"
#include "Entidade/Obstaculo/PlataformaMovel.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    Fase::Fase():
    pGColisoes(nullptr)
    {
        pGColisoes = new Gerenciador::GerenciadorColisoes(&listaEnt);
        //criarFase();
    }

    Fase::~Fase() {
        delete pGColisoes;
    }

    void Fase::criarPlataforma(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::Plataforma(x, y);
        if (objEntidade)
            listaEnt.incluir(objEntidade);
    }


    void Fase::criarFase() {

    }

    void Fase::executar() {
        Entidade::Entidade::getTempoFrame();
        listaEnt.percorrer();
        pGColisoes->executar();

    }


}
