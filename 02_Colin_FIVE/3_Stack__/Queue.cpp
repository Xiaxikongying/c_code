#include <iostream>
#include <time.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *Head;
    Node *Tail;
    int count;
} Queue;

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->next = NULL;
    return p;
}

Queue *getNewQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->count = 0;
    q->Head = q->Tail = NULL;
    return q;
}

Queue *push(Queue *q, int key)
{
    if (q == NULL)
        return NULL;
    Node *p = getNewNode(key);
    if (q->Head == NULL)
    {
        q->Head = q->Tail = p;
        q->count++;
    }
    else
    {
        q->Tail->next = p;
        q->Tail = p;
        q->count++;
    }
    return q;
}

Queue *pop(Queue *q)
{
    if (q == NULL)
        return NULL;
    if (q->Head == NULL)
        return q;

    Node *p = q->Head;
    q->Head = p->next;
    free(p);
    q->count--;
    return q;
}

int front(Queue *q)
{
    if(q->count == 0)
    {
        cout << "无节点" << endl;
        return -1;
    }
    return q->Head->data;
}

int isEmpty(Queue *q)
{
    if(q->count == 0)
        return 1;
    return 0;
}

void output(Queue *q)
{
    if (q->Head == NULL)
    {
        cout << "队列为空" << endl;
        return;
        
    }
    Node *p = q->Head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    printf("\n");
}

int main()
{
    srand(time(0));
    Queue *q = getNewQueue();
    int a;
    for (int i = 0; i < 8; i++)
    {
        a = rand() % 50;
        q = push(q, a);
        //cout << a << endl;
    }
    output(q);
    q = pop(q);
    q = pop(q);
    output(q);

    cout << "是否为空" << isEmpty(q) << endl;
    cout << "首部元素为：" << front(q) << endl;

    system("pause");
    return 0;
}

/*
push pop 是void


void push(Queue *q, int key)
{
    if (q == NULL)
        return ;
    Node *p = getNewNode(key);
    if (q->Head == NULL)
    {
        q->Head = q->Tail = p;
        q->count++;
    }
    else
    {
        q->Tail->next = p;
        q->Tail = p;
        q->count++;
    }
}

void pop(Queue *q)
{
    if (q == NULL)
        return;
    if (q->Head == NULL)
        return;
    Node *p = q->Head;
    q->Head = p->next;
    free(p);
    q->count--;
}

int main()
{
    srand(time(0));
    Queue *q = getNewQueue();
    int a;
    for (int i = 0; i < 8; i++)
    {
        a = rand() % 50;
        push(q, a);
        // cout << a << endl;
    }
    output(q);
    pop(q);
    pop(q);
    output(q);

    cout << "是否为空" << isEmpty(q) << endl;
    cout << "首部元素为：" << front(q) << endl;

    system("pause");
    return 0;
}

*/