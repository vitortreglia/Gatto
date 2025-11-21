#include "Fase/Fase.h"

#include "Entidade/Itens/Peixe.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "../../includes/Entidade/Chao.h"
#include "Entidade/Obstaculo/PlataformaMovel.h"
#include "Entidade/Personagem/Inimigo/Gaivota.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include <ctime>

namespace Fase {
    Fase::Fase(int nFase):
    Ente(&fundo),
    pGColisoes(nullptr),
    limitesFase({0,0,0,0}),
    numFase(nFase),
    maxInimGaivota(10),
    maxPMovel(15),
    numInimGaivota(0),
    numPMovel(0),
    numJogs(1),
    buffer(nullptr)
    {
        pGColisoes = new Gerenciador::GerenciadorColisoes(&listaEnt);
        pGGrafico->resetaRelogio();
        semearRand();
    }

    Fase::~Fase() {
        delete pGColisoes;
    }

    void Fase::semearRand() {
        srand(time(0));
    }

    sf::FloatRect Fase::getLimitesFase() {
        return limitesFase;
    }

    void Fase::criarChao(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Chao(x, y+50, numFase);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirChao(static_cast<Entidade::Chao*>(objEntidade));
        }
    }

    void Fase::criarPlataformaMovel(float x, float y, bool direcao) {
        if ((rand()%10 <= 10 || numPMovel < 3) && numPMovel < maxPMovel) {
            Entidade::Entidade* objEntidade = new Entidade::Obstaculo::PlataformaMovel(x, y+50, direcao);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
                numPMovel++;
            }
        } else if (direcao){
            criarChao(x, y + 200);
            criarChao(x + 100, y + 200);
        } else {
            criarChao(x, y - 200);
            criarChao(x + 100, y - 200);
        }
    }

    void Fase::criarPeixe(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Itens::Peixe(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->incluirPeixe(static_cast<Entidade::Itens::Peixe*>(objEntidade));
        }
    }

    void Fase::criarInimigoGaivota(float x, float y) {
        if ((rand()%10 <= 10 || numInimGaivota < 3) && numInimGaivota < maxInimGaivota) {
            Entidade::Entidade* objEntidade = new Entidade::Personagem::Inimigo::Gaivota(x, y);
            if (objEntidade) {
                listaEnt.incluir(objEntidade);
                pGColisoes->incluirInimigo(static_cast<Entidade::Personagem::Inimigo::Inimigo*>(objEntidade));
                numInimGaivota++;
            }
        }
    }

    void Fase::atualizarEntidades() {
        for (int i = 0; i < listaEnt.getTam(); i++) {
            if (listaEnt[i]->estaAtivo())
                listaEnt[i]->executar();
        }
        pGColisoes->executar();
        for (int i = 0; i < listaEnt.getTam(); i++) {
            if (listaEnt[i]->estaAtivo())
                listaEnt[i]->desenhar();
        }
    }

    const int Fase::getFase() const {
        return numFase;
    }

    void Fase::criarCenario(string caminho) {
        multimap<char, sf::Vector2f> obstaculos;
        multimap<char, sf::Vector2f> inimigos;
        ifstream arquivo(caminho);
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
                    obstaculos.insert({linha[i], {x, y}});
                    x += 100.0f;
                } else if (linha[i] == 'm' || linha[i] == 'n' || linha[i] == 'g' || linha[i] == 'o' || linha[i] == 'O') {
                    obstaculos.insert({linha[i], {x, y}});
                    x += 200.0f;
                } else if (linha[i] == 'g' || linha[i] == 'v' || linha[i] == 'r' || linha[i] == 'c') {
                    inimigos.insert({linha[i], {x, y}});
                    x += 200.0f;
                } else if (linha[i] == 'f') {
                    criarPeixe(x, y);
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
        criarInimigos(inimigos);
        criarObstaculos(obstaculos);
    }

    void Fase::executar() {
        Entidade::Entidade::getTempoFrame();
        atualizarEntidades();
    }

    void Fase::salvar() {
        ofstream salvamento("Data/Fases/save.txt", ios::out);
        if (!salvamento) {
            cerr << " Arquivo não pode ser aberto " << endl;
            fflush ( stdin );
            getchar( );
            return;
        }
        salvamento << numJogs << ' ' << numFase << endl;
        for (int i = 0; i < listaEnt.getTam(); i++) {
            listaEnt[i]->salvar(salvamento);
        }
        salvamento.close();
    }

}
