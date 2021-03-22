//����������������������������˫��ѭ������ģ���ࡪ��������������������������
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
    //�޲ι��캯��
    DoubleCirLinklist();
    //�вι��캯�� nΪ����
    DoubleCirLinklist(int n);
    //��������
    ~DoubleCirLinklist();
    //���������ǽ���ڼ���
    void SetMark(int x);
    //�ƶ���� direction�ƶ����� 1Ϊ����0Ϊ���� step�ƶ�����
    void Move(bool direction, int step);
    //ɾ����ǰ���λԪ�� directionΪ�ƶ����򣬣�����directionԭ����ȷ��ɾ��Ԫ�غ�markӦ������һλ��������һλ��
    int Delete(bool direction);
    //�����Ԫ��
    void Print();
private:
    //ͷ���ָ��
    Node* head;
    //���λָ��
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