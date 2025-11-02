#include "Fase/FaseJardim.h"
#include "Entidade/Obstaculo/Obstaculo.h"
#include "Entidade/Obstaculo/PlataformaGiratoria.h"
#include "Entidade/Obstaculo/PlataformaMovel.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Fase {
    FaseJardim::FaseJardim():
    maxInimFaceis(0),
    maxInimMedios(0)
    {
        listaEnt.incluir(new Entidade::Personagem::Jogador());
        pGColisoes->addJogador(static_cast<Entidade::Personagem::Jogador*>(listaEnt[0]));
        criarFaseTorre();
    }

    FaseJardim::~FaseJardim() {

    }

    void FaseJardim::criarPlataformaMovel(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::PlataformaMovel(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->addObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }

    void FaseJardim::criarPlataformaGiratoria(float x, float y) {
        Entidade::Entidade* objEntidade = new Entidade::Obstaculo::PlataformaGiratoria(x, y);
        if (objEntidade) {
            listaEnt.incluir(objEntidade);
            pGColisoes->addObstaculo(static_cast<Entidade::Obstaculo::Obstaculo*>(objEntidade));
        }
    }


    void FaseJardim::criarFaseTorre() {
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
                    criarPlataformaMovel(x, y);
                    x += 200.0f;
                } else if (linha[i] == 'g') {
                    criarPlataformaGiratoria(x, y);
                }
                x += espaco * 100.0f;
                espaco = 0;
            }
            y += 100.0f;
            x = 0.0f;
        }
        arquivo.close();
    }


}
