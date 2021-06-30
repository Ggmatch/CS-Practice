#include <iostream>
#include "MyString.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    string s1 = "123";
    string s2(s1);
    string s3 = s1 + s2;
    string s4("456");
    s4 += s3;
    cout << s << ";" << s1 << ";" << s2 << ";" << s3 << ";" << s4 << endl;
    MyString ms;
    MyString ms1 = "123";
    MyString ms2(ms1);
    MyString ms3 = ms1 + ms2;
    MyString ms4("456");
    ms4 += ms3;
    cout << ms << ";" << ms1 << ";" << ms2 << ";" << ms3 << ";" << ms4 << endl;

    return 0;
}
