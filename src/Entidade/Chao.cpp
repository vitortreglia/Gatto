#include "../../includes/Entidade/Chao.h"
namespace Entidade {
        Chao::Chao(float x, float y, int fase):
        Entidade(sf::Vector2f(100,50), x, y),
        imgFaseJardim("Data/Imagens/grama.png"),
        imgFaseCidade("Data/Imagens/parapeito.png")
        {
            if (fase == 1)
                textura.inserirTextura("base", imgFaseJardim);
            else
                textura.inserirTextura("base", imgFaseCidade);
            textura.setAnimacao("base");
        }

        Chao::~Chao() {

        }

        void Chao::obstaculizar(Personagem::Jogador* pJog) {

        }

        void Chao::executar() {
            //textura.animar(false);
            //desenhar();
        }
}