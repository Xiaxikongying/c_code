#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//此处用 链表 来实现队列

typedef struct Node
{
    int data;
    Node *next;
} Node;

Node *getNewNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

//-------------------------------------------------------------------------------------

typedef struct LinkList
{
    Node head;
    Node *tail;
} LinkList;

LinkList *initLinkList()
{
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    L->head.next = NULL;
    L->tail = &(L->head);
    return L;
}
void clearLinkList(LinkList *L)
{
    Node *p = L->head.next, *q;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    return;
}
int emptyList(LinkList *L)
{
    return L->head.next == NULL;
}

int frontList(LinkList *L)
{
    if (emptyList(L))
        return 0;
    return L->head.next->data;
}

int insertTail(LinkList *L, int val)
{
    Node *node = getNewNode(val);
    L->tail->next = node;
    L->tail = node;
    return 1;
}

int eraseHead(LinkList *L)
{
    if (emptyList(L))
        return 0;
    Node *p = L->head.next;
    L->head.next = L->head.next->next;
    if (p == L->tail)
        L->tail = &(L->head);
    free(p);
    return 1;
}

//-------------------------------------------------------------------------------------

typedef struct Queue
{
    LinkList *l; // l表示data的存储空间
    int count;
    // int size;  //链表 无假溢出 无须记录size
    // int head, tail; // head tail  也不需要
    //链表有自己的指针
} Queue;

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->l = initLinkList();
    q->count = 0;
    return q;
}
int isempty(Queue *q)
{
    return q->count == 0;
}
int front(Queue *q)
{
    if (isempty(q))
        return 0;
    return frontList(q->l);
}

int push(Queue *q, int val)
{
    insertTail(q->l, val);
    q->count++;
    return 1;
}
int pop(Queue *q)
{
    eraseHead(q->l);
    q->count--;
    return 1;
}

void clearQueue(Queue *q)
{
    if (q == NULL)
        return;
    clearLinkList(q->l);
    free(q);
    return;
}

void printQueue(Queue *q)
{
    printf("Queue :");
    Node *p = q->l->head.next;
    for (int i = 0; i < q->count; i++, p = p->next)
    {
        printf("%4d", p->data);
    }
    printf("\n\n\n");
    return;
}

#define Max_op 10
int main()
{
    srand(time(0));
    Queue *q = initQueue();
    for (int i = 0; i < Max_op; i++)
    {
        int op = rand() % 5; // 0:pop  1,2,3,4:push
        int val = rand() % 100;
        switch (op)
        {
        case 0:
            if (isempty(q))
            {
                printf("No data can be popped ");
                break;
            }
            printf("front of queue : %d", front(q));
            printf("     pop %d from queue \n", front(q));
            pop(q);
            break;

        case 1:
        case 2:
        case 3:
        case 4:
            printf("push %d to queue \n", val);
            push(q, val);
            break;
        }
        printQueue(q);
    }
    clearQueue(q);
    system("pause");
    return 0;
}
