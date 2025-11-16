#include "Fase/FaseCidade.h"

#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/Plataforma.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Entidade/Personagem/Inimigo/Cachorro.h"

namespace Fase {

    FaseCidade::FaseCidade() :
    Fase(IDs::Ente_IDs::FaseCidade)
    {
        criarFaseCidade();
    }

    FaseCidade::~FaseCidade() {

    }
    void FaseCidade::criarFaseCidade() {

    }
}