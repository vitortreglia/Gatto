#ifndef OBSERVADOR_H
#define OBSERVADOR_H

class Observer {
public:
    virtual ~Observer() = default;
    virtual void notificar() = 0;
protected:
    Observer() = default;
};

#endif //OBSERVADOR_H
