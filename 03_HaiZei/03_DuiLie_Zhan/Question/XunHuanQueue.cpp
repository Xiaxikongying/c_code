#include <iostream>
using namespace std;
// leetcode----622
/*
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。

*/

struct Node
{
    int data;
    Node *next;
};

class MyCircularQueue
{
public:
    Node *head, *tail;
    int count;
    int size;
    MyCircularQueue(int k)
    {
        head = new node();
        tail = head;
        count = 0;
        size = k;

        for (int i = 1; i < l; i++)
        {
            tail->next = new Node();
            tail = tail->next;
        }
        tail->next = head;
        return;
    }

    bool enQueue(int value)
    {
        if(isFull())
            return false;
        tail = tail->next;
        tail->data = value;
        count++;
        return true;
    }

    bool deQueue()  //删除第一个
    {
        if (isEmpty())
            return false;
        head = head->next;
        count--;
        return true;
    }

    int Front()
    {
        if(isEmpty())
            return -1;
        return head->data;
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return tail->data;
    }

    bool isEmpty()
    {
        return == 0;
    }

    bool isFull()
    {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */