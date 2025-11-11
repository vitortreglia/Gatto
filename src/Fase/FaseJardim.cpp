#include "Fase/FaseJardim.h"

#include "Entidade/Itens/Projetil.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/PlataformaGiratoria.h"
#include "Entidade/Obstaculo/PlataformaMovel.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    FaseJardim::FaseJardim():
    Fase(IDs::Ente_IDs::FaseJardim),
    maxInimFaceis(0),
    maxInimMedios(0)
    {
        listaEnt.incluir(new Entidade::Personagem::Jogador());
        pGColisoes->incluirJogador(static_cast<Entidade::Personagem::Jogador*>(listaEnt[0]));
        criarFaseJardim();
    }

    FaseJardim::~FaseJardim() {

    }

    void FaseJardim::criarPlataformaMovel(float x, float y, bool direcao) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::PlataformaMovel(x, y, direcao);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void FaseJardim::criarPlataformaGiratoria(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::PlataformaGiratoria(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void FaseJardim::criarInimigoGaivota(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Gaivota(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
        }
    }

    void FaseJardim::criarFaseJardim() {
        ifstream arquivo("Data/Fases/FaseJardim.dat");
        int espaco = 0;
        float x = 0.0f;
        float y = 100.0f;
        if (!arquivo.is_open()) {
            cout << "Erro ao abrir o arquivo!\n";
        }
        std::string linha;
        while (getline(arquivo, linha)) {
            for (int i = 0; i < linha.size(); i++) {
                if (linha[i] >= '0' && linha[i] <= '9') {
                    espaco = linha[i] - '0';
                } else if (linha[i] >= 'A' && linha[i] <= 'F') {
                    espaco = 10 + (linha[i] - 'A');
                } else if (linha[i] == 'p') {
                    criarPlataforma(x, y);
                    x += 100.0f;
                } else if (linha[i] == 'm') {
                    criarPlataformaMovel(x, y, false);
                    x += 200.0f;
                } else if (linha[i] == 'n') {
                    criarPlataformaMovel(x, y, true);
                    x += 200.0f;
                } else if (linha[i] == 'g') {
                    criarPlataformaGiratoria(x, y);
                    x += 200.0f;
                } else if (linha[i] == 'v') {
                    criarInimigoGaivota(x, y);
                    x += 100.0f;
                } else if (linha[i] == 'f') {
                    criarPeixe(x, y);
                    x += 100.0f;
                } else if (linha[i] == 'r') {
                    criarInimigoRato(x, y);
                    x += 100.0f;
                }
                x += espaco * 100.0f;
                espaco = 0;
            }
            if (x > limitesFase.width)
                limitesFase.width = x;
            y += 100.0f;
            x = 0.0f;
        }
        limitesFase.height = y;
        arquivo.close();
        pGGrafico->setLimitesCamera(limitesFase);
    }
}
