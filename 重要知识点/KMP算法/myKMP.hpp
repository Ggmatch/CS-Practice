#pragma once

#include <string>
#include <vector>
#include <ostream>
using namespace std;

class MyKMP
{
private:
    string s1;        //主字符串
    string s2;        //模式字符串
    vector<int> next; //模式串的next数组
    void getNext();   // 获取模式串的next数组
public:
    MyKMP(string, string);
    ~MyKMP();
    int find();                                     // 在s1中匹配字符串s2，成功再返回开始下标，否则返回-1
    friend ostream &operator<<(ostream &, MyKMP &); // 查看next数组
};

MyKMP::MyKMP(string s1, string s2) : s1(s1), s2(s2), next(s2.size(), -1)
{
    getNext();
}

MyKMP::~MyKMP()
{
}

int MyKMP::find()
{
    int i, j; //i代表当前遍历主字符串的下标，j代表遍历模式字符串的下标
    i = j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (j == -1 || s1[i] == s2[j]) // 从头开始匹配或者正在匹配
        {
            i++;
            j++;
        }
        else
            j = next[j]; // 匹配失败，取重新开始匹配的位置
    }
    return j == s2.size() ? i - j : -1;
}

void MyKMP::getNext()
{
    int i = 0, j = -1;
    while (i < s2.size()) // 模式串作为主字符串，遍历当前位置i
    {
        if (j == -1 || s2[i] == s2[j]) // 模式串来匹配主字符串
        {
            i++;
            j++;
            next[i] = j; // 得到当前位置的next值
        }
        else
            j = next[j];
    }
}

ostream &operator<<(ostream &out, MyKMP &myKMP)
{
    vector<int> &tmp = myKMP.next;
    for (auto iter = tmp.begin(); iter != tmp.end(); iter++)
        out << *iter << " ";
    return out;
}