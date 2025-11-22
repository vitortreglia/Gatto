#ifndef GERENCIADOREVENTOS_H
#define GERENCIADOREVENTOS_H
#include "GerenciadorGrafico.h"
#include "Observer/Subject.h"
#include <set>

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
