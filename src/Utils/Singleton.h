#pragma once
#include <memory>

template <class T>
class Singleton
{
protected:
    Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    virtual ~Singleton() = default;

public:
    static T &GetInstance()
    {
        static T instance;
        return instance;
    }
};
