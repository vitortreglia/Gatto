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
    private:
        GerenciadorEvento();
    public:
        ~GerenciadorEvento();
        static GerenciadorEvento* getGerenciadorEvento();
        std::set<sf::Keyboard::Key> getTeclasPressionadas();
        std::set<sf::Keyboard::Key> getTeclasSoltas();
        void verificaTeclasPressionadas(sf::Event evento);
        void verificaTeclaSolta();
        void executar();
    };
}

#endif //GERENCIADOREVENTOS_H
