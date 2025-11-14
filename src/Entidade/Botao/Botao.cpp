#include "Entidade/Botao/Botao.h"
namespace Entidade {
    Botao::Botao(string rotulo):
    Entidade({400.0f, 100.0f}, 440, 100, IDs::Ente_IDs::Botao),
    textoBotao(rotulo, 28, 600.0f, 140.0f)
    {}

    Botao::~Botao() {

    }

    void Botao::desenhar() {
        pGGrafico->desenharUI(&corpo);
    }

    void Botao::executar() {
        desenhar();
        textoBotao.executar();
    }
}