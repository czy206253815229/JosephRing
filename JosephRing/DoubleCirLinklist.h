//——————————————双向循环链表模板类——————————————
#pragma once
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class DoubleCirLinklist
{
public:
    //无参构造函数
    DoubleCirLinklist();
    //有参构造函数 n为人数
    DoubleCirLinklist(int n);
    //析构函数
    ~DoubleCirLinklist();
    //设置最初标记结点在几号
    void SetMark(int x);
    //移动标记 direction移动方向 1为正向，0为反向， step移动步数
    void Move(bool direction, int step);
    //删除当前标记位元素 direction为移动方向，（保留direction原因是确定删除元素后mark应该在下一位还是在上一位）
    int Delete(bool direction);
    //输出环元素
    void Print();
private:
    //头结点指针
    Node* head;
    //标记位指针
    Node* mark;
};

DoubleCirLinklist::DoubleCirLinklist()
{
    head = NULL;
    mark = NULL;
}

DoubleCirLinklist::DoubleCirLinklist(int n)
{
    Node *node, *end;
    head = new Node;
    mark = head;
    end = head;
    head->data = 1;
    head->next = head;
    head->prev = head;
    for (int i = 2; i <= n; i++)
    {
        node = new Node;
        node->data = i;
        end->next = node;
        node->prev = end;
        node->next = NULL;
        end = node;
    }
    end->next = head;
    head->prev = end;
}

DoubleCirLinklist::~DoubleCirLinklist()
{
    Node* node;
    while (head->next != head)
    {
        node = head->next;
        head->next = node->next;
        node->next->prev = head;
        node->next = NULL;
        node->prev = NULL;
        delete node;
        node = NULL;
    }
}

void DoubleCirLinklist::SetMark(int x)
{
    Node* node = head;
    while (node->next != head && node->data != x)
    {
        node = node->next;
    }
    if (node->data == x)
        mark = node;
    else
        throw "wrong parameter";
}

int DoubleCirLinklist::Delete(bool direction)
{
    int index;
    index = mark->data;
    Node* node;
    if (direction)
    {
        mark = mark->next;
        node = mark->prev;
        node->prev->next = mark;
        mark->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        delete node;
        node = NULL;
        head = mark;
    }
    else
    {
        mark = mark->prev;
        node = mark->next;
        node->next->prev = mark;
        mark->next = node->next;
        node->next = NULL;
        node->prev = NULL;
        delete node;
        node = NULL;
        head = mark;
    }
    return index;
}

void DoubleCirLinklist::Move(bool direction, int step)
{
    if (direction)
    {
        for (int i = 0; i < step; i++)
        {
            mark = mark->next;
        }
    }
    else
    {
        for (int i = 0; i < step; i++)
        {
            mark = mark->prev;
        }
    }
}

void DoubleCirLinklist::Print()
{
    Node* node;
    node = head;
    do
    {
        cout << node->data << " ";
        node = node->next;
    }     
    while (node != head);
}