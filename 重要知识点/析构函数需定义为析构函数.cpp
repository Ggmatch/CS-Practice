#include <iostream>
using namespace std;

class Person
{
public:
    Person() { cout << "Person constructor" << endl; };
    // ~Person() { cout << "Person deconstructor" << endl; }; //析构函数不定义为虚函数
    virtual ~Person() { cout << "Person deconstructor" << endl; };
};

class Stu : public Person
{
public:
    Stu() { cout << "Stu constructor" << endl; };
    virtual ~Stu() { cout << "Stu deconstructor" << endl; };
};

int main()
{
    Person *p = new Stu();
    delete p; //释放
    return 0;
}