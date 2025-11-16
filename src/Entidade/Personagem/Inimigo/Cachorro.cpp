#include "Entidade/Personagem/Inimigo/Cachorro.h"
#include "Entidade/Itens/Projetil.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Gerenciador/GerenciadorEvento.h"
#include "Ente_IDs.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {

            Cachorro::Cachorro(float x, float y) :
            ataque(1, 0.8f),
            Inimigo(0, 150.0f, {200.0f, 300.0f}, x, y, 8, IDs::Ente_IDs::InimigoCachorro),
            raioPercepcaoX(300.0f),
            raioAtaque(230.0f),
            velocidade(150.0f)


            {
                corpo.setFillColor(sf::Color(139, 69, 19));
                vMax.x = velocidade;
                andar(true);
            }

            Cachorro::~Cachorro() {

            }
            void Cachorro::atualizaMaldade() {

                if (nivelMaldade <= 0) {
                    fatorFuria = 1.0f;
                    raioPercepcaoX = 300.0f;
                    raioAtaque = 230.0f;
                }
                else if (nivelMaldade == 1) {
                    fatorFuria = 1.25;
                    raioPercepcaoX = 350.0f;
                    raioAtaque = 270.0f;
                }
                else if (nivelMaldade == 2) {
                    fatorFuria = 1.5;
                    raioPercepcaoX = 400.0f;
                    raioAtaque = 300.0f;
                }
                else {
                    fatorFuria = 2.0f;
                    raioPercepcaoX = 450.0f;
                    raioAtaque = 350.0f;
                }
                    vMax.x = velocidade * fatorFuria;
            }

            void Cachorro::patrulhar() {
                if (std::rand() % 150 == 0) {
                    andar(!direita);
                }
            }
            void Cachorro::perseguir() {
                if (!pJog)
                    return;

                sf::Vector2f posJog = pJog->getPosicao();
                sf::Vector2f pos = getPosicao();
                float dx = posJog.x - pos.x;

                andar(dx > 0.0f);

                if (posJog.y + 40.0f < pos.y && estaNoChao) {
                    deslocamento.y = -30.0f;
                    estaNoChao(false);
                }
            }
            void Cachorro::criarOsso() {

                sf::Vector2f tam = getTamanho();
                sf::Vector2f pos = getPosicao();

                float posX;
                if (posX = direita)
                    pos.x + tam.x;
                else
                    pos.x - 20.0f;

                float posY = pos.y + tam.y / 2.0f;

                Itens::Projetil* osso = new Itens::Projetil(posX, posY, direita);
            }

            void Cachorro::atirarOsso() {
                // fazer else/if pra ir ver o nivel de maldade e decidir quantos osso atacar
            }

            void Cachorro::executar() {
                mover();
                verificaVidas();
            }

        }
    }
}
