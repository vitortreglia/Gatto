#ifndef GATTO_ARMAINIMIGO_H
#define GATTO_ARMAINIMIGO_H

#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Itens/Arma.h"


namespace Entidade {
    namespace Itens {
        class ArmaInimigo : public Arma {
        public:
            ArmaInimigo(IDs::IDs id, int forca);
            ~ArmaInimigo();
            void executar();
            void atacar();
            void colisao(sf::Vector2f colisao, Entidade *pEntidade);
        };
    }
}

#endif //GATTO_ARMAINIMIGO_H