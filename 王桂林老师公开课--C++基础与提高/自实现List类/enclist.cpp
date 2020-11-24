#include "List.hpp"
using namespace std;


int main()
{
    List l;
    l.initList();
    for(int i=0;i<10;i++)
    {
        l.insertList(i);
    }
    l.destroy();
    
    return 0;
}
