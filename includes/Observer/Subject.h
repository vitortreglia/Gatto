#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include <SFML/Window/Event.hpp>
#include "Observer.h"

/*  Subject
*
*      Implementacao do padrao Observer, utilizado pelas classes do namespace Estados e
*      pela classe Jogador, realizado conforme o livro Padroes de Projeto, de Erich Gamma,
*      Richard Helm, Ralph Johnson e John Vlissides
*
*/

class Subject {
protected:
    std::list<Observer*> observers;
    std::list<Observer*> remover;
    std::list<Observer*> adicionar;
public:
    virtual ~Subject() = default;
    void inscrever(Observer* pO);
    void desinscrever(Observer* pO);
protected:
    Subject();
    virtual void notificar();
};

#endif //SUBJECT_H
