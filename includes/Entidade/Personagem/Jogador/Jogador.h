#ifndef JOGADOR_H
#define JOGADOR_H
#include "Entidade/Personagem/Personagem.h"
#include "UI/Texto.h"
#include "Entidade/Personagem/Ataque.h"
#include "Entidade/Itens/Peixe.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Observer/Observer.h"

namespace Entidade {
    namespace Personagem {
        class Jogador : public Personagem, public Observer {
        private:
            int pontos;
            int numJog;
            Ataque ataque;
            bool podePular;
            int peixes;
            float deslocAtaque;
            Texto interface;
            bool imunidadeDano;
            bool vencedor;
        public:
            Jogador(int nJog, int p);
            ~Jogador();
            bool getVencedor();
            void observarEntrada();
            void ignorarEntrada();
            void liberaPulo();
            void pular(float multiplicador);
            void coletarPeixe();
            const bool perderPeixe();
            const bool getImunidadeDano() const;
            void colidir(Inimigo::Inimigo* pInimigo, sf::Vector2f colisao);
            void colidir(sf::Vector2f colisao);
            void tomarDano(int dano);
            void verificaVidas();
            void pontuar(int p);
            int getPontuacao();
            void mover();
            void executar();
            void tratarEventos();
            void notificar();
            void lerDataBuffer();
            void carregar(istream &entrada);
            void salvar(ostream& saida);
            void salvarDataBuffer();
            void operator++();
            const bool operator--();
        };
    }
}

#endif //JOGADOR_H
