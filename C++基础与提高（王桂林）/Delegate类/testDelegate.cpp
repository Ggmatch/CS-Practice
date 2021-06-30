#include <iostream>
#include "Delegate.hpp"
using namespace std;

int main()
{
    Delegate d(5);
    d.setValue(100);
    cout<<d.getValue()<<endl;
    return 0;
}