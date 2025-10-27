#include "Gerenciador/GerenciadorColisoes.h"

namespace Gerenciador {
    GerenciadorColisoes::GerenciadorColisoes(Lista::ListaEntidades *pLPersonagens) {
        pListaPersonagens = pLPersonagens;
    }

    GerenciadorColisoes::~GerenciadorColisoes() {
        pListaPersonagens = nullptr;
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


    float GerenciadorColisoes::calcularColisao(Entidade::Entidade* corpo1, Entidade::Entidade* corpo2) {
        vector<sf::Vector2f> coordCorpo1 = corpo1->getCoordenadas();
        vector<sf::Vector2f> coordCorpo2 = corpo2->getCoordenadas();
        vector<sf::Vector2f> normais;
        float overlap = 999999.0f;
        for (int i = 0; i < 2; i++) {
            normais.push_back(calculaNormal(coordCorpo1[i], coordCorpo1[i + 1]));
            normais.push_back(calculaNormal(coordCorpo2[i], coordCorpo2[i + 1]));
        }
        vector<pair<float, float>> projecaoC1 = calculaProjecao(coordCorpo1, normais);
        vector<pair<float, float>> projecaoC2 = calculaProjecao(coordCorpo2, normais);
        /*bool colisao = true;
        for (int i = 0; i < 4; i++) {
            if (projecaoC1[i].second < projecaoC2[i].first || projecaoC2[i].second < projecaoC1[i].first)
                colisao = false;
        }
        if (colisao) {*/
        for (int i = 0; i < 4; i++) {
            if (overlap > projecaoC1[i].second - projecaoC2[i].first)
                overlap = projecaoC1[i].second - projecaoC2[i].first;
            if (overlap > projecaoC2[i].second - projecaoC1[i].first)
                overlap = projecaoC2[i].second - projecaoC1[i].first;
        }/*
        } else {
            overlap = 0.0f;
        }*/
        return overlap;
    }

    void GerenciadorColisoes::executar() {
        Entidade::Entidade* obj1 = nullptr;
        Entidade::Entidade* obj2 = nullptr;
        obj1 = pListaPersonagens->operator[](0);
        obj2 = pListaPersonagens->operator[](2);
        float colisao = calcularColisao(obj1, obj2);
        if (colisao > 0.0f) {
            obj1->colisao(colisao);

        }
        //obj2 = pListaPersonagens->operator[](2);
        //if (ds.y)
    }


}