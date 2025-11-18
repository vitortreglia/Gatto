#include "Entidade/Obstaculo/Plataforma.h"
namespace Entidade {
    namespace Obstaculo {
        Plataforma::Plataforma(float x, float y, int fase):
        Obstaculo(false, sf::Vector2f(100,50), x, y),
        imgFaseJardim("Data/Imagens/grama.png"),
        imgFaseCidade("Data/Imagens/parapeito.png")
        {
            if (fase == 1)
                textura.inserirTextura("base", imgFaseJardim);
            else
                textura.inserirTextura("base", imgFaseCidade);
            textura.setAnimacao("base");
        }

        Plataforma::~Plataforma() {

        }

        void Plataforma::obstaculizar(Personagem::Jogador* pJog) {

        }

        void Plataforma::executar() {
            //textura.animar(false);
            //desenhar();
        }


    }
}