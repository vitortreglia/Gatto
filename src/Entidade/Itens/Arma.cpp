#include "Entidade/Itens/Arma.h"

namespace Entidade {
    namespace Itens {
        Arma::Arma(IDs::IDs id):
        Entidade({100.0f, 30.0f}, -1000.0f, -1000.0f, id) {}


    }
}