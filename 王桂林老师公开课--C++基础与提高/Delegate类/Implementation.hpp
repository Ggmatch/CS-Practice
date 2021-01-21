#pragma once

class Implementation
{
private:
    int value;

public:
    Implementation(int v);
    ~Implementation();
    void setValue(int v)
    {
        value = v;
    }
    int getValue() const
    {
        return value;
    }
};

Implementation::Implementation(int v) : value(v) {}

Implementation::~Implementation()
{
}
