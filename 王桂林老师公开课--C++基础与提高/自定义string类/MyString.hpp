#pragma once
#include <ostream>

class MyString
{
private:
    char *_str;

public:
    MyString(const char *str = nullptr);
    MyString(const MyString &other);
    friend std::ostream &operator<<(std::ostream &os, const MyString &ms);
    ~MyString();
    const char *c_str() const; //后面const修饰函数体，表明该成员函数不修改类的数据成员
    friend MyString operator+(const MyString &left, const MyString &right);
    MyString &operator+=(const MyString &right);
    int size() const;
};

MyString::MyString(const char *str)
{
    if (str != nullptr)
    {
        int len = strlen(str);
        _str = new char[len + 1];
        strcpy(_str, str);
    }
    else
    {
        _str = new char[1];
        *_str = '\0';
    }
}

const char *MyString::c_str() const
{
    return _str;
}

MyString::MyString(const MyString &other)
{
    //深拷贝
    const char *tmp = other.c_str();
    int len = strlen(tmp);
    _str = new char[len + 1];
    strcpy(_str, tmp);
}

MyString::~MyString()
{
    if (_str != nullptr)
    {
        delete[] _str;
    }
}

std::ostream &operator<<(std::ostream &os, const MyString &ms)
{
    os << ms.c_str();
    return os;
}

MyString operator+(const MyString &left, const MyString &right)
{
    int leftLength = left.size();
    int rightLength = right.size();

    int totalLength = leftLength + rightLength;
    char str[totalLength + 1];
    strcpy(str, left._str);
    strcpy(str + leftLength, right._str);
    return MyString(str);
}

MyString& MyString::operator+=(const MyString &right)
{
    int leftLength = this->size();
    int rightLength = right.size();

    int totalLength = leftLength + rightLength;
    char str[leftLength + 1];
    strcpy(str,this->_str);
    delete []this->_str;

    this->_str = new char[totalLength+1];
    strcpy(this->_str, str);
    strcpy(this->_str + leftLength, right._str);

    return *this;
}

int MyString::size() const
{
    return strlen(this->_str);
}