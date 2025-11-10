#include "Entidade/Personagem/Ataque.h"

namespace Entidade {
    Ataque::Ataque(int forca):
    dano(forca),
    podeAtacar(true),
    tempoAtaque(0.0f),
    tMaxAtaque(0.1f)
    {}

    Ataque::~Ataque() {}

    int Ataque::getForca() {
        return dano;
    }

    void Ataque::atacar() {
        if (podeAtacar) {
            podeAtacar = false;
            atacando = true;
        }
    }

    bool Ataque::getAtacando() {
        return atacando;
    }

    void Ataque::liberaAtaque() {
        podeAtacar = true;
    }

    int Ataque::getDano() {
        return dano;
    }

    void Ataque::ataque(float tempoFrame) {
        tempoAtaque += tempoFrame;
        if (tempoAtaque > tMaxAtaque) {
            tempoAtaque = 0.0f;
            atacando = false;
        }
    }


}