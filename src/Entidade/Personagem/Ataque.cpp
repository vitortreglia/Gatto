#include "Entidade/Personagem/Ataque.h"

namespace Entidade {
    Ataque::Ataque(int forca, float tMaxAtk):
    dano(forca),
    podeAtacar(true),
    tempoAtaque(0.0f),
    tMaxAtaque(tMaxAtk)
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
        if (atacando) {
            tempoAtaque += tempoFrame;
            if (tempoAtaque > tMaxAtaque) {
                tempoAtaque = 0.0f;
                atacando = false;
            }
        }
    }

    float Ataque::getTempoAtaque() {
        return tempoAtaque;
    }

    void Ataque::setTempoAtaque(float t) {
        tempoAtaque = t;
    }

}