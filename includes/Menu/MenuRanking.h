#ifndef MENURANKING_H
#define MENURANKING_H
#include "Menu.h"


namespace Menu {
    class MenuRanking: public Menu {
    private:
        Animacao fundo;
        multimap<int, string, std::greater<int>> ranking;
    public:
        MenuRanking(multimap<int, string, std::greater<int>> r);
        ~MenuRanking();
        void criarMenuRanking();

    };
}


#endif //MENURANKING_H
