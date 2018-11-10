#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

template<class T>
class Singleton
{

protected:
    Singleton() {}

public:
    static T * getInstance() {
        static T * instance = new T();
        return instance;
    }

};

#endif // SINGLETON_H
