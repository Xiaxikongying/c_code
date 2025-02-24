#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define father(i) ((i) / 2)
#define left(i) ((i)*2)
#define right(i) ((i)*2 + 1)

#define swap(a, b)             \
    {                          \
        __typeof(a) __c = (a); \
        (a) = (b);             \
        (b) = __c;             \
    }

typedef struct PriorityQueue
{
    int *data;   //指针
    int *__data; //真正的数据
    int size, n;
} PriorityQueue;

PriorityQueue *initPQ(int size)
{
    PriorityQueue *p = (PriorityQueue *)malloc(sizeof(PriorityQueue));

    p->__data = (int *)malloc(sizeof(int) * size);
    p->data = p->__data - 1; //下标偏移 使得 data[0] --->  __data[1]

    p->size = size;
    p->n = 0;
    return p;
}

void clearPQ(PriorityQueue *p)
{
    if (p == NULL)
        return;
    free(p->__data);
    free(p);
    return;
}

int empty(PriorityQueue *p)
{
    return p->n == 0;
}
int full(PriorityQueue *p)
{
    return p->n == p->size;
}
int top(PriorityQueue *p)
{
    return p->data[1];
}

/*1.递归实现
void up_updata(int *data, int i)
{
    //当前插入节点大于它的父节点 需要向上调整
    if (i == 1)
        return;
    if (data[i] > data[father(i)])
        swap(data[i], data[father(i)]);
    up_updata(data, father(i));

}*/
// 2.循环诗选
void up_updata(int *data, int i)
{
    while (i > 1 && data[i] > data[father(i)])
    {
        swap(data[i], data[father(i)]);
        i = father(i);
    }
    return;
}

void down_updata(int *data, int i, int n)
{
    int ind, l, r;
    while (l <= n)
    {
        ind = i, l = left(i), r = right(i);
        if (data[l] > data[ind])
            ind = l;
        if (r <= n && data[r] > data[ind])
            ind = r;
        if (ind == i)
            break;
        swap(data[i], data[ind]);
        i = ind;
    }
    return;
}

int push(PriorityQueue *p, int x)
{
    if (full(p))
        return 0;
    p->n += 1;
    p->data[p->n] = x;
    up_updata(p->data, p->n); //向上调整
    return 1;
}

int pop(PriorityQueue *p)
{
    if (empty(p))
        return 0;
    p->data[1] = p->data[p->n];
    p->n -= 1;
    down_updata(p->data, 1, p->n);
    return 1;
}

void output(PriorityQueue *p)
{
    printf("PQ(%d): ", p->n);
    for (int i = 1; i <= p->n; i++)
    {
        printf("%d ", p->data[i]);
    }
    printf("\n");
}

int main()
{
    int op, x;
    PriorityQueue *p = initPQ(100);
    while (~scanf("%d", &op))
    {
        if (op == 1)
        {
            scanf("%d", &x);
            printf("insert %d to PQ: \n", x);
            push(p, x);
            output(p);
        }
        else
        {
            printf("top: %d\n", top(p));
            pop(p);
            output(p);
        }
    }
    clearPQ(p);

    system("pause");
    return 0;
}