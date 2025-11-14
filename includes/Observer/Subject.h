#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include <SFML/Window/Event.hpp>
#include "Observer.h"

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
