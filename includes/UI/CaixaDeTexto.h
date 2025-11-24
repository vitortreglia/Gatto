#ifndef CAIXADETEXTO_H
#define CAIXADETEXTO_H
#include "Texto.h"
#include "Gerenciador/GerenciadorEvento.h"

/*  CaixaDeTexto
 *
 *      Implementacao autoral com base em conhecimentos adquiridos estudando a documentacao
 *      da biblioteca SFML. Documentacao disponivel em https://www.sfml-dev.org/documentation/2.6.2/
 *
 */

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
