#include "Fase/FaseCidade.h"
#include "Entidade/Obstaculo/Roseira.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Inimigo/Rato.h"

namespace Fase {
    FaseCidade::FaseCidade(Entidade::Personagem::Jogador *pJog1, Entidade::Personagem::Jogador *pJog2):
    Fase("Data/Imagens/fundoJardim.jpg", 2),
    maxChefoes(5),
    maxRoseiras(20),
    numRoseira(0),
    numInimChefao(0)
    {
        pJog1->setPosicao({1500, 2200});
        listaEnt.incluir(pJog1);
        if (pJog2) {
            pGGrafico->setMultiplayer(true);
            pJog2->setPosicao({2700, 2200});
            listaEnt.incluir(pJog2);
        }
        Entidade::Personagem::Inimigo::Inimigo::setJogadores(pJog1, pJog2);
        pGColisoes->incluirJogadores(pJog1, pJog2);
        criarFaseCidade();
    }

    FaseCidade::~FaseCidade() {

    }

    void FaseCidade::criarProjetil(float x, float y, bool direita,
        Entidade::Personagem::Inimigo::Cachorro* pCachorro) {

        if (!pCachorro)
            return;

        sf::Vector2f pos = pCachorro->getPosicao();

        Entidade::Itens::Projetil* proj = new Entidade::Itens::Projetil();

        if (proj) {
            proj->setAtivo(false);
            proj->setDirecao(direita);
            proj->setPosicao(pos);

            listaEnt.incluir(proj);
            pGColisoes->incluirProjetil(proj);

            pCachorro->setProjetil(proj);
        }
    }

    void FaseCidade::criarChefao(float x, float y) {
        if ((rand()%10 < 9 || numInimChefao < 3) && numInimChefao < maxChefoes) {
            auto* cachorro = new Entidade::Personagem::Inimigo::Cachorro(x, y);
            if (cachorro) {
                listaEnt.incluir(cachorro);
                pGColisoes->incluirInimigo(
                    static_cast<Entidade::Personagem::Inimigo::Inimigo*>(cachorro)
                );
                numInimChefao++;
                criarProjetil(x, y, true, cachorro);
        }
    }

    void FaseCidade::criarRoseira(float x, float y, bool danoso) {
        if ((rand()%10 < 9 || numRoseira < 3) && numRoseira < maxRoseiras) {
            Entidade::Entidade* objEntidade = new Entidade::Obstaculo::Roseira(danoso, x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
                numRoseira++;
            }
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
