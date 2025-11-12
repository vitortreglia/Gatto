#include "Observer/Subject.h"

Subject::Subject() {}

void Subject::inscrever(Observer *pO) {
    if (pO)
        if (observers.empty())
            observers.push_back(pO);
        else
            adicionar.push_back(pO);
}

void Subject::desinscrever(Observer *pO) {
    if (pO)
        remover.push_back(pO);
}

void Subject::notificar() {
    for (std::list<Observer*>::const_iterator it = observers.begin(); it != observers.end(); it++) {
        (*it)->notificar();
    }
    for (std::list<Observer*>::const_iterator it = remover.begin(); it != remover.end(); it++) {
        observers.remove(*it);
    }
    observers.merge(adicionar);
    adicionar.clear();
    remover.clear();
}
