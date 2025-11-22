#ifndef OBSERVADOR_H
#define OBSERVADOR_H
namespace Gerenciador {
    class GerenciadorEvento;
}

class Observer {
protected:
    static Gerenciador::GerenciadorEvento* pGEvento;
public:
    virtual ~Observer() = default;
    virtual void notificar() = 0;
protected:
    Observer() = default;
};

#endif //OBSERVADOR_H
