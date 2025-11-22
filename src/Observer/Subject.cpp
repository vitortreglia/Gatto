#include "Observer/Subject.h"

Subject::Subject() {}

void Subject::inscrever(Observer *pO) {
    if (pO) {
        adicionar.push_back(pO);
    }
}

void Subject::desinscrever(Observer *pO) {
    if (pO)
        remover.push_back(pO);
}

void Subject::notificar() {
    for (std::list<Observer*>::const_iterator it = remover.begin(); it != remover.end(); it++) {
        observers.remove(*it);
    }
    remover.clear();
    for (std::list<Observer*>::const_iterator it = observers.begin(); it != observers.end(); it++) {
        bool removido = (std::find(remover.begin(), remover.end(), *it) != remover.end());
        if (!removido) {
            (*it)->notificar();
        }
    }

    observers.splice(observers.end(), adicionar);
    adicionar.clear();
}
