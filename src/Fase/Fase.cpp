#include "Fase/Fase.h"

#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    Fase::Fase():
    pGColisoes(nullptr)
    {
        pGColisoes = new Gerenciador::GerenciadorColisoes(&listaPersonagens);
        criarFase();
    }

    Fase::~Fase() {
        delete pGColisoes;
    }

    void Fase::criarFase() {
        Entidade::Entidade* objEntidade = new Entidade::Personagem::Jogador();
        listaPersonagens.incluir(objEntidade);
        objEntidade = nullptr;
        /*objEntidade = new Entidade::Personagem::Personagem(100.0f);
        objEntidade->setPosicao(sf::Vector2f(200.0f, 100.0f));
        listaPersonagens.incluir(objEntidade);*/
        objEntidade = nullptr;
        objEntidade = new Entidade::Obstaculo::Obstaculo();
        listaPersonagens.incluir(objEntidade);
        objEntidade = nullptr;
        objEntidade = new Entidade::Obstaculo::Obstaculo();
        objEntidade->setPosicao(sf::Vector2f(0.0f, 300.0f));
        objEntidade->setTamanho(sf::Vector2f(200.0f, 100.0f));
        listaPersonagens.incluir(objEntidade);
    }

    void Fase::executar() {
        pGColisoes->executar();
        listaPersonagens.operator[](2)->executar();
        //listaPersonagens.operator[](3)->executar();
        listaPersonagens.operator[](1)->executar();
        listaPersonagens.operator[](0)->executar();

    }


}
