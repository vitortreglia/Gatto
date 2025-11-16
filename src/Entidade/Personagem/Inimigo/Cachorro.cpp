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
            velocidade(150.0f);


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
                    furioso = false;
                    raioPercepcaoX = 300.0f;
                    raioAtaque = 230.0f;
                }
                else if (nivelMaldade == 1) {
                    fatorFuria = 1.25;
                    furioso = false;
                    raioPercepcaoX = 350.0f;
                    raioAtaque = 270.0f;
                }
                else if (nivelMaldade == 2) {
                    fatorFuria = 1.5;
                    furioso = true;
                    raioPercepcaoX = 400.0f;
                    raioAtaque = 300.0f;
                }
                else {
                    fatorFuria = 2.0f;
                    furioso = true;
                    raioPercepcaoX = 450.0f;
                    raioAtaque = 350.0f;
                }
                    vMax.x = velocidade * fatorFuria;
            }

            void Cachorro::patrulhar() {

                if (std::rand() % 180 == 0) {
                    andar(!direita);
                }

            }
        }
    }
}
