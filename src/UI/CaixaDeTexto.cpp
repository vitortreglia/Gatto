#include "UI/CaixaDeTexto.h"

CaixaDeTexto::CaixaDeTexto() :
conteudo("", 36, 0, 0),
caixa({400, 50}),
Ente(&caixa),
digitando(false)
{
    conteudo.setFonte("Data/Fontes/KirangHaerang-Regular.ttf");
    conteudo.setCor(0, 0, 0, 255);
    caixa.setFillColor(sf::Color::White);
    caixa.setOutlineColor(sf::Color::Black);
    caixa.setOutlineThickness(5);
}

CaixaDeTexto::~CaixaDeTexto() {

}

void CaixaDeTexto::setPosicao(float x, float y) {
    caixa.setPosition({x, y});
    conteudo.setPosicao(x+10, y);
}

void CaixaDeTexto::entradaDeTexto() {
    sf::Uint32 c = 0;
    string texto;
    c = pGEvento->getEntradaTexto();
    if (c != 0 && c != 32) {
        if (c == 10) {
            ignorarEntrada();
            return;
        }
        texto = conteudo.getTexto();
        if (c == 8) {
            if (!texto.empty())
                texto.erase(texto.size() - 1);
        } else
            texto += (char)c;
        conteudo.setTexto(texto);
    }
    if (!digitando) {
        ignorarEntrada();
    }
}

void CaixaDeTexto::executar() {
    pGGrafico->desenharUI(&caixa);
    conteudo.desenhar();
}

void CaixaDeTexto::notificar() {
    entradaDeTexto();
}

void CaixaDeTexto::observarEntrada() {
    pGEvento->inscrever(this);
}

void CaixaDeTexto::ignorarEntrada() {
    pGEvento->desinscrever(this);
}

string CaixaDeTexto::getEntrada() {
    return conteudo.getTexto();
}

void CaixaDeTexto::setDigitando(bool d) {
    digitando = d;
}

bool CaixaDeTexto::getDigitando() {
    return digitando;
}

sf::FloatRect CaixaDeTexto::getCoordCaixa() {
    return caixa.getGlobalBounds();
}
