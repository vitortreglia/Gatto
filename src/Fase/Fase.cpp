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
        criarFase();
    }

    Fase::~Fase() {
        delete pGColisoes;
    }

    void Fase::criarFase() {
        Entidade::Entidade* objEntidade = new Entidade::Personagem::Jogador();
        listaEnt.incluir(objEntidade);
        objEntidade = nullptr;
        objEntidade = new Entidade::Obstaculo::PlataformaGiratoria(sf::Vector2f(200.0f, 50.0f), 550.0f, 400.0f, 100.0f);
        listaEnt.incluir(objEntidade);
        objEntidade = new Entidade::Obstaculo::Plataforma(sf::Vector2f(2000.0f, 100.0f), 0.0f, 620.0f);
        listaEnt.incluir(objEntidade);

    }

    void Fase::executar() {
        pGColisoes->executar();
        Entidade::Entidade::getTempoFrame();
        listaEnt.operator[](1)->executar();
        listaEnt.operator[](2)->executar();
        listaEnt.operator[](0)->executar();

    }


}
