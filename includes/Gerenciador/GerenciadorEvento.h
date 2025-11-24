#ifndef GERENCIADOREVENTOS_H
#define GERENCIADOREVENTOS_H
#include "GerenciadorGrafico.h"
#include "Observer/Subject.h"
#include <set>

/*  Gerenciador de Eventos feito usando o Padrao de Projeto Singleton e Observer
 *
 *      Implementacao de padrao de projeto Singleton baseada no material disponibilizado
 *      pelo então monitor Giovane Limas Salvi, no 2º semestre de 2022 em
 *      https://www.youtube.com/watch?v=gfGE5KY1OQU e
 *      https://github.com/Giovanenero/JogoPlataforma2D-Jungle/tree/main
 *
 *      Implementacao do Padrao Observer baseada no livro Padroes de Projeto, de
 *      Erich Gamma, Richard Helm, Ralph Johnson e John Vlissides
 *
 */

namespace Gerenciador {
    class GerenciadorEvento: public Subject {
    private:
        static GerenciadorEvento* pGEvento;
        GerenciadorGrafico* pGGrafico;
        std::set<sf::Keyboard::Key> teclasAtivas;
        std::set<sf::Keyboard::Key> teclasSoltas;
        sf::Uint32 c;
        sf::Vector2f clique;
    private:
        GerenciadorEvento();
    public:
        ~GerenciadorEvento();
        static GerenciadorEvento* getGerenciadorEvento();
        std::set<sf::Keyboard::Key> getTeclasPressionadas();
        std::set<sf::Keyboard::Key> getTeclasSoltas();
        sf::Uint32 getEntradaTexto();
        sf::Vector2f getClique();
        void verificaTeclasPressionadas(sf::Event evento);
        void executar();
    };
}

#endif //GERENCIADOREVENTOS_H
