#pragma once
#include "Implementation.hpp"

class Delegate
{
private:
    Implementation* pi;
public:
    Delegate(int );
    ~Delegate();
    void setValue(int v)
    {
        pi->setValue(v);
    }
    int getValue() const
    {
        return pi->getValue();
    }
};

Delegate::Delegate(int v):pi(new Implementation(v))
{
}

Delegate::~Delegate()
{
}
