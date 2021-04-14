#include <iostream>
#include "myKMP.hpp"
using namespace std;

int main()
{
    string s1 = "ababababca", s2 = "abababca";
    MyKMP myKMP(s1, s2);
    cout << "匹配开始下标：" << myKMP.find() << endl;
    cout << "模式串next数组：" << myKMP << endl;
    return 0;
}