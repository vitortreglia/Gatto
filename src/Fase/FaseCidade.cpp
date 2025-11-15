#include "Fase/FaseCidade.h"

#include "Entidade/Obstaculo/Roseira.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Inimigo/Rato.h"

namespace Fase {
    FaseCidade::FaseCidade(Entidade::Personagem::Jogador *pJog1, Entidade::Personagem::Jogador *pJog2):
    Fase(IDs::Ente_IDs::FaseCidade, "Data/Imagens/fundoJardim.jpg"),
    maxChefoes(5),
    maxInimGaivota(8)
    {
        pJog1->setPosicao({1500, 2200});
        listaEnt.incluir(pJog1);
        if (pJog2) {
            pGGrafico->setMultiplayer(true);
            pJog2->setPosicao({2700, 2200});
            listaEnt.incluir(pJog2);
        }
        Entidade::Personagem::Inimigo::Gaivota::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        criarFaseCidade();
    }

    FaseCidade::~FaseCidade() {

    }

    void FaseCidade::criarProjetil(float x, float y, bool direita) {
        if (direita) {
            x += 80.0f;
        }
        Entidade::Entidade* objEntidade = new Entidade::Itens::Projetil(x, y, direita);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirProjetil(static_cast<Entidade::Itens::Projetil*>(objEntidade));
        }
    }

    void FaseCidade::criarChefao(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Rato(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
        }
    }

    void FaseCidade::criarRoseira(float x, float y, bool danoso) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::Roseira(danoso, x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void FaseCidade::criarFaseCidade() {
        ifstream arquivo("Data/Fases/FaseCidade.dat");
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
                } else if (linha[i] == 'r') {
                    criarRoseira(x, y, true);
                    x += 200.0f;
                } else if (linha[i] == 'R') {
                    criarRoseira(x, y, false);
                    x += 200.0f;
                } else if (linha[i] == 'v') {
                    criarInimigoGaivota(x, y);
                    x += 100.0f;
                } else if (linha[i] == 'f') {
                    criarPeixe(x, y);
                    x += 100.0f;
                } else if (linha[i] == 'c') {
                    criarChefao(x, y);
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
