#include "Fase/Fase.h"

#include "Entidade/Itens/Peixe.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/Plataforma.h"
#include "Entidade/Obstaculo/PlataformaMovel.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    Fase::Fase(IDs::Ente_IDs id, string caminhoTextura):
    Ente(id, &fundo),
    pGColisoes(nullptr),
    limitesFase({0,0,0,0}),
    fundo({1280, 720})
    {
        texturaFundo.setTextura(caminhoTextura);
        pGColisoes = new Gerenciador::GerenciadorColisoes(&listaEnt);
        pGGrafico->setFundo(&texturaFundo);
        pGGrafico->resetaRelogio();
        //criarFase();
    }

    Fase::~Fase() {
        delete pGColisoes;
    }

    sf::FloatRect Fase::getLimitesFase() {
        return limitesFase;
    }

    void Fase::criarPlataforma(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::Plataforma(x, y+50);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void Fase::criarPlataformaMovel(float x, float y, bool direcao) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::PlataformaMovel(x, y+50, direcao);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void Fase::criarPeixe(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Itens::Peixe(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirPeixe(static_cast<Entidade::Itens::Peixe*>(objEntidade));
        }
    }

    void Fase::criarInimigoGaivota(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Gaivota(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
        }
    }

    void Fase::atualizarEntidades() {
        for (int i = 0; i < listaEnt.getTam(); i++) {
            if (listaEnt[i]->estaAtivo())
                listaEnt[i]->executar();
        }
        pGColisoes->executar();
        for (int i = 0; i < listaEnt.getTam(); i++) {
            if (listaEnt[i]->estaAtivo())
                listaEnt[i]->desenhar();
        }
    }

    void Fase::executar() {
        Entidade::Entidade::getTempoFrame();
        atualizarEntidades();
    }
}
