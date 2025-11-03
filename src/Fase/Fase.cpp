#include "Fase/Fase.h"

#include "Entidade/Itens/Peixe.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/Plataforma.h"
#include "Entidade/Obstaculo/PlataformaGiratoria.h"
#include "Entidade/Obstaculo/PlataformaMovel.h"
#include "Entidade/Personagem/Inimigos/Inimigo.h"
#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Personagem/Inimigos/Gaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    Fase::Fase():
    pGColisoes(nullptr),
    limitesFase({0,0,0,0})
    {
        pGColisoes = new Gerenciador::GerenciadorColisoes(&listaEnt);
        //criarFase();
    }

    Fase::~Fase() {
        delete pGColisoes;
    }

    sf::FloatRect Fase::getLimitesFase() {
        return limitesFase;
    }


    void Fase::criarPlataforma(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::Plataforma(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->addObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void Fase::criarPeixe(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Itens::Peixe(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->addPeixe(static_cast<Entidade::Itens::Peixe*>(objEntidade));
        }
    }


    void Fase::criarFase() {

    }

    void Fase::executar() {
        Entidade::Entidade::getTempoFrame();
        listaEnt.percorrer();
        pGColisoes->executar();
    }





}
