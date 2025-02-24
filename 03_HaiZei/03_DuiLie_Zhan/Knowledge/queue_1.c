#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//队列 先进先出 只能从头出  只能从尾巴进

//此处用顺序表来实现队列

typedef struct Vector
{
    int *data;
    int size;
} Vector;

Vector *initVector(int n)
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->size = n;
    v->data = (int *)malloc(sizeof(int) * n);
    return v;
}

void clearVector(Vector *v)
{
    if (v == NULL)
        return;
    free(v->data);
    free(v);
    return;
}

int VectorSeek(Vector *v, int pos)
{
    if (pos < 0 || pos >= v->size)
        return -1;
    return v->data[pos];
}

int insertVector(Vector *v, int pos, int val)
{
    if (pos < 0 || pos >= v->size)
        return -1;
    v->data[pos] = val;
    return 1;
}

//---------------------------------------------------------------

typedef struct Queue
{
    Vector *data;
    int size, count;
    int head, tail; // head tail 只是作为下标  不是指针
} Queue;

Queue *initQueue(int n)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = initVector(n);
    q->size = n;
    q->head = q->tail = q->count = 0;
    return q;
}

bool isempty(Queue *q)
{
    return q->count == 0;
}
int front(Queue *q)
{
    return VectorSeek(q->data, q->head);
}

int push(Queue *q, int val)
{
    if (q->size == q->count)
        return 0;
    insertVector(q->data, q->tail, val);
    q->tail++;
    if (q->tail == q->size)
        q->tail == 0;
    q->count++;
    return 1; //表示入队成功
}
int pop(Queue *q)
{
    if (isempty(q))
        return 0;
    q->head++;
    q->count--;
    return 1;
}

void clearQueue(Queue *q)
{
    if (q == NULL)
        return;
    clearVector(q->data);
    free(q);
    return;
}

void printQueue(Queue *q)
{
    printf("Queue :");
    for (int i = 0; i < q->count; i++)
    {
        printf("%4d", VectorSeek(q->data, (q->head + i) % q->size));
    }
    printf("\n\n\n");
    return;
}

#define Max_op 10
int main()
{
    srand(time(0));
    Queue *q = initQueue(5);
    for (int i = 0; i < Max_op; i++)
    {
        int op = rand() % 5; // 0:pop  1,2,3,4:push
        int val = rand() % 100;
        switch (op)
        {
        case 0:
            if (isempty(q))
            {
                printf("No data can be poped ");
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
