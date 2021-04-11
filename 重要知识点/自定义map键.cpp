#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person(string ,int );
    ~Person();
    friend ostream& operator<<(ostream& , const Person& );
    string getName() const;  //必须是const，与classcomp中匹配
    int getAge() const;
};

Person::Person(string name,int age):name(name),age(age)
{
}

Person::~Person()
{
}

ostream& operator<<(ostream& os, const Person& p)
{
    os<<"("<<p.name<<","<<p.age<<")";
    return os;
}

string Person::getName() const
{
    return name;
}

int Person::getAge() const
{
    return age;
}

struct classcomp
{
    bool operator()(const Person& p1,const Person& p2) const  //形式固定这样，不可修改
    {
        return p1.getName()<p2.getName();
    }
};


int main()
{
    map<Person,int,classcomp> m1;
    Person keys[]={Person("a",23),Person("c",24),Person("b",21)};
    int values[]={1,2,3};
    for(int i=0;i<3;i++)
        m1[keys[i]]=values[i];
    for(auto iter=m1.begin();iter!=m1.end();iter++)
        cout<<"m1.key="<<iter->first<<" m1.value="<<iter->second<<endl;
    
    return 0;
}