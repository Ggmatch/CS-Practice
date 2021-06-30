#pragma once

#include <iostream>
using namespace std;


struct Node
{
    int data;   //数据域
    Node *next; //指针域
};

class List
{
public:
    void initList();              //初始化，建立个哑结点
    void insertList(int data);            //尾插
    void deleteNode(Node *pfind); //删除指定结点
    Node *searchList(int find);   //查找指定值的结点
    void destroy();               //从头开始，顺序销毁
private:
    Node *head;
    Node *last; //尾部指针
};

void List::initList()
{
    head = new Node{-1,nullptr};
    last = head;
}

void List::insertList(int data)
{
    if (last != nullptr)
    {
        Node *tmp = new Node{data, nullptr};
        last->next = tmp;
        last = tmp;
    }
}

void List::deleteNode(Node *pfind)
{
    Node *tmp = head;
    while (tmp->next && tmp->next != pfind)
    {
        tmp = tmp->next;
    }
    if (tmp->next)
    {
        Node *tmp1 = tmp->next->next;
        delete tmp->next;
        tmp->next = tmp1;
    }
}

Node* List::searchList(int find)
{
    Node* tmp = head->next;
    while(tmp && tmp->data!=find)
    {
        tmp=tmp->next;
    }
    return tmp;  //未找到，返回nullptr
}

void List::destroy()
{
    while (head != nullptr)
    {
        Node *tmp = head->next;
        cout<<"销毁："<<head->data<<endl;
        delete head;
        head = tmp;
    }
}