
#ifndef INIMIGO_H
#define INIMIGO_H

#include "Entidade/Personagem/Personagem.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigos {
            class Inimigo : public Personagem {
            public:
                Inimigo ();
                virtual ~Inimigo();
            };
        }
    }
}

#endif
