#ifndef OBSERVADOR_H
#define OBSERVADOR_H
namespace Gerenciador {
    class GerenciadorEvento;
}

/*  Observer
*
*      Implementacao do padrao Observer, utilizado pelas classes do namespace Estados e
*      pela classe Jogador, realizado conforme o livro Padroes de Projeto, de Erich Gamma,
*      Richard Helm, Ralph Johnson e John Vlissides
*
*/

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
