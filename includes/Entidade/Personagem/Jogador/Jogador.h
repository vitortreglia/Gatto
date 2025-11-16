#ifndef JOGADOR_H
#define JOGADOR_H
#include "Entidade/Personagem/Personagem.h"
#include "Texto.h"
#include "Entidade/Personagem/Ataque.h"
#include "Entidade/Itens/Peixe.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Observer/Observer.h"

namespace Entidade {
    namespace Personagem {
        class Jogador : public Personagem, public Observer {
        private:
            static Gerenciador::GerenciadorEvento* pGEvento;
            int numJog;
            Ataque ataque;
            bool podePular;
            int peixes;
            float deslocAtaque;
            Texto interface;
            bool imunidadeDano;
            bool vencedor;
            string imgGato1;
            string imgGato2;
        public:
            Jogador(int nJog);
            ~Jogador();
            bool getVencedor();
            static void setGerenciadorEvento();
            void observarEntrada();
            void ignorarEntrada();
            void liberaPulo();
            void pular(float multiplicador);
            void coletarPeixe(Itens::Peixe* pPeixe);
            const bool perderPeixe();
            const bool getImunidadeDano() const;
            void colidir(Inimigo::Inimigo* pInimigo, sf::Vector2f colisao);
            void colidir(sf::Vector2f colisao);
            void tomarDano(int dano);
            void verificaVidas();
            void mover();
            void executar();
            void tratarEventos();
            void notificar();
        };
    }
}

#endif //JOGADOR_H
