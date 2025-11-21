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
            Obstaculo(bool dano, sf::Vector2f tamanho, float x, float y);
            ~Obstaculo();
            virtual void obstaculizar(Personagem::Jogador* pJog) = 0;
            virtual void executar() = 0;
            void lerDataBuffer();
            void carregar(istream &entrada) = 0;
            void salvarDataBuffer();
            virtual void salvar(ostream& saida) = 0;
        };
    }
}
#endif //OBSTACULO_H
