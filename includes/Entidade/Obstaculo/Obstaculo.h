    #ifndef OBSTACULO_H
#define OBSTACULO_H
#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

    namespace Entidade {
    namespace Obstaculo {
        class Obstaculo : public Entidade {
        protected:
            bool danoso;
        public:
            Obstaculo(bool dano, sf::Vector2f tamanho, float x, float y, IDs::Ente_IDs id);
            ~Obstaculo();
            virtual void obstaculizar(Personagem::Jogador* pJog) = 0;
            virtual void executar() = 0;
        };
    }
}
#endif //OBSTACULO_H
