#ifndef JOGADOR_H
#define JOGADOR_H
#include "../Personagem.h"

namespace Entidade {
    namespace Personagem {
        class Jogador : public Personagem {
        private:
        public:
            Jogador();
            ~Jogador();
            void move();
            sf::RectangleShape* getCorpo();
        };
    }
}

#endif //JOGADOR_H
