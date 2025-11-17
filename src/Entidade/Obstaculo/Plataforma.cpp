#include "Entidade/Obstaculo/Plataforma.h"
namespace Entidade {
    namespace Obstaculo {
        Plataforma::Plataforma(float x, float y):
        Obstaculo(false, sf::Vector2f(100,50), x, y),
        imgFaseJardim("Data/Imagens/grama.png"){
            textura.setTextura(imgFaseJardim);
            setTextura(&textura);
        }

        Plataforma::~Plataforma() {

        }

        void Plataforma::obstaculizar(Personagem::Jogador* pJog) {

        }

        void Plataforma::executar() {
            //desenhar();
        }


    }
}