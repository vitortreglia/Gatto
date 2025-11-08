#include "Entidade/Personagem/Ataque.h"

namespace Entidade {
    Ataque::Ataque(int forca):
    dano(forca),
    tempoAtaque(0.0f),
    tMaxAtaque(0.1f)
    {}

    Ataque::~Ataque() {}

    int Ataque::getForca() {
        return dano;
    }

    void Ataque::setAtacando(bool atk) {
        atacando = atk;
    }

    bool Ataque::getAtacando() {
        return atacando;
    }

    int Ataque::getDano() {
        return dano;
    }

    void Ataque::ataque(float tempoFrame) {
        tempoAtaque += tempoFrame;
        if (tempoAtaque > tMaxAtaque) {
            setAtacando(false);
            tempoAtaque = 0.0f;
        }
    }


}