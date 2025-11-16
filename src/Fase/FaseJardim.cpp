#include "Fase/FaseJardim.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/GiraGira.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Inimigo/Rato.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    FaseJardim::FaseJardim(Entidade::Personagem::Jogador* pJog1, Entidade::Personagem::Jogador* pJog2):
    Fase("Data/Imagens/fundoJardim.jpg", 1),
    maxInimRato(8),
    maxGiraGira(8),
    numInimRato(0),
    numGiraGira(0)
    {
        pJog1->setPosicao({1600, 4600});
        listaEnt.incluir(pJog1);
        if (pJog2) {
            pGGrafico->setMultiplayer(true);
            pJog2->setPosicao({2000, 4600});
            listaEnt.incluir(pJog2);
        }
        Entidade::Personagem::Inimigo::Gaivota::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        criarFaseJardim();
    }

    FaseJardim::~FaseJardim() {

    }

    void FaseJardim::criarGiraGira(float x, float y) {
        if ((rand()%10 < 9 || numGiraGira < 3) && numGiraGira < maxGiraGira) {
            Entidade::Entidade* objEntidade = new Entidade::Obstaculo::GiraGira(x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
                numGiraGira++;
            }
        }
    }

    void FaseJardim::criarInimigoRato(float x, float y) {
        if ((rand()%10 < 9 || numInimRato < 3) && numInimRato < maxInimRato) {
            Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Rato(x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
                numInimRato++;
            }
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
                    criarGiraGira(x, y);
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
