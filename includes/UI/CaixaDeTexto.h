#ifndef CAIXADETEXTO_H
#define CAIXADETEXTO_H
#include "Texto.h"
#include "Gerenciador/GerenciadorEvento.h"


class CaixaDeTexto : public Ente, public Observer {
private:
    Texto conteudo;
    sf::RectangleShape caixa;
    bool digitando;
public:
    CaixaDeTexto();
    ~CaixaDeTexto();
    void entradaDeTexto();
    void setPosicao(float x, float y);
    void executar();
    void notificar();
    void observarEntrada();
    void ignorarEntrada();
    string getEntrada();
    void setDigitando(bool d);
    bool getDigitando();
    sf::FloatRect getCoordCaixa();
};



#endif //CAIXADETEXTO_H
