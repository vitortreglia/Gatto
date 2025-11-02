 #include "Gerenciador/GerenciadorColisoes.h"

namespace Gerenciador {
    GerenciadorColisoes::GerenciadorColisoes(Lista::ListaEntidades *pLPersonagens) {
        pListaPersonagens = pLPersonagens;
    }

    GerenciadorColisoes::~GerenciadorColisoes() {
        pListaPersonagens = nullptr;
    }

    void GerenciadorColisoes::addObstaculo(Entidade::Obstaculo::Obstaculo *obs) {
        if (obs)
            LOs.push_back(obs);
    }

    void GerenciadorColisoes::addJogador(Entidade::Personagem::Jogador* pJog) {
        pJogador1 = pJog;
    }


    sf::Vector2f GerenciadorColisoes::calculaNormal(const sf::Vector2f& vertice1, const sf::Vector2f& vertice2) {
        sf::Vector2f normal;
        float modulo;

        normal.x = - (vertice1.y - vertice2.y);
        normal.y = vertice1.x - vertice2.x;
        modulo = sqrt(normal.x * normal.x + normal.y * normal.y);
        normal.x = normal.x / modulo;
        normal.y = normal.y / modulo;

        return normal;
    }

    vector<pair<float, float>> GerenciadorColisoes::calculaProjecao(const vector<sf::Vector2f> &vertices, const vector<sf::Vector2f> &normal) {
        vector<pair<float,float>> projecoes = {{9999999.0f, -9999999.0f}, {9999999.0f, -9999999.0f}, {9999999.0f, -9999999.0f}, {9999999.0f, -9999999.0f}};
        float resultado;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                resultado = vertices[j].x * normal[i].x + vertices[j].y * normal[i].y;
                if (projecoes[i].first > resultado)
                    projecoes[i].first = resultado;
                if (projecoes[i].second < resultado)
                    projecoes[i].second = resultado;
            }
        }
        return projecoes;
    }

    sf::Vector2f GerenciadorColisoes::calculaSobreposicao(vector<sf::Vector2f> coordCorpo1, vector<sf::Vector2f> coordCorpo2) {
        vector<sf::Vector2f> normais;
        for (int i = 0; i < 2; i++) {
            normais.push_back(calculaNormal(coordCorpo1[i], coordCorpo1[i + 1]));
            normais.push_back(calculaNormal(coordCorpo2[i], coordCorpo2[i + 1]));
        }

        vector<pair<float, float>> projecaoC1 = calculaProjecao(coordCorpo1, normais);
        vector<pair<float, float>> projecaoC2 = calculaProjecao(coordCorpo2, normais);

        float sobreposicao = 999999.0f;
        sf::Vector2f deltaSobreposicao;

        for (int i = 0; i < 4; i++) {
            if (sobreposicao > projecaoC1[i].second - projecaoC2[i].first) {
                sobreposicao = projecaoC1[i].second - projecaoC2[i].first;
                deltaSobreposicao.x = - normais[i].x * sobreposicao;
                deltaSobreposicao.y = - normais[i].y * sobreposicao;
            }
            if (sobreposicao > projecaoC2[i].second - projecaoC1[i].first) {
                sobreposicao = projecaoC2[i].second - projecaoC1[i].first;
                deltaSobreposicao.x = normais[i].x * sobreposicao;
                deltaSobreposicao.y = normais[i].y * sobreposicao;
            }
        }

        if (sobreposicao <= 0.0f) {
            deltaSobreposicao.x = 0.0f;
            deltaSobreposicao.y = 0.0f;
        }
        return deltaSobreposicao;
    }


    sf::Vector2f GerenciadorColisoes::verificarColisao(Entidade::Entidade* corpo1, Entidade::Entidade* corpo2) {
        vector<sf::Vector2f> coordCorpo1 = corpo1->getCoordenadas();
        vector<sf::Vector2f> coordCorpo2 = corpo2->getCoordenadas();

        return calculaSobreposicao(coordCorpo1, coordCorpo2);
    }

    void GerenciadorColisoes::tratarColisoesJogsObstacs() {
        Entidade::Entidade* obj1 = nullptr;
        Entidade::Entidade* obj2 = nullptr;

        obj1 = pJogador1;
        sf::Vector2f colisao;
        for (list<Entidade::Obstaculo::Obstaculo*>::const_iterator it = LOs.begin(); it != LOs.end(); it++) {
            colisao = verificarColisao(obj1, *it);
            if (colisao.x != 0.0f || colisao.y != 0.0f) {
                obj1->colisao(colisao);
            }
        }
    }


    void GerenciadorColisoes::executar() {
        tratarColisoesJogsObstacs();
    }


}