#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>

typedef struct Node
{
    int key, level;
    struct Node *next, *down, *up;
} Node;

#define MAX_LEVEL 32
#define min(a, b) (a) < (b) ? (a) : (b)

Node *getNewNode(int key, int n)
{
    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++)
    {
        nodes[i].key = key;
        nodes[i].level = i;
        nodes[i].next = NULL;
        nodes[i].down = (i ? nodes + (i - 1) : NULL);
        nodes[i].up = (i + 1 < n ? nodes + (i + 1) : NULL);
    }
    return nodes + n - 1;
}

typedef struct Skiplist
{
    Node *head, *tail;
    int max_level;

} Skiplist;

Skiplist *getNewSkiplist(int n)
{
    Skiplist *s = (Skiplist *)malloc(sizeof(Skiplist));
    s->head = getNewNode(INT32_MIN, n); //头节点为最小值  都为 n 层
    s->tail = getNewNode(INT32_MAX, n); //尾节点为最大值
    Node *p = s->head;
    Node *q = s->tail;
    s->max_level = n;
    while (p)
    {
        //将头和尾相连
        p->next = q;
        p = p->down;
        q = q->down;
    }
    while (s->head->level != 0)
        s->head = s->head->down;
    return s;
}

void clearNode(Node *p)
{
    if (p == NULL)
        return;
    free(p);
    return;
}

void clearSkiplist(Skiplist *s)
{
    Node *p = s->head, *q;
    while (p->level != 0)
        p = p->down; //使p指向第0层

    while (p)
    {
        q = p->next;
        clearNode(p);
        p = q;
    }
    free(s);
    return;
}

Node *find(Skiplist *s, int x)
{
    Node *p = s->head;
    while (p && p->key != x)
    {
        if (p->next->key <= x)
            p = p->next;
        else
            p = p->down;
    }
    return p;
}

void insert(Skiplist *s, int x)
{
    int level = rand() % 5 + 1;
    printf("rand level = %d  insert data = %d \n", level, x);
    while (s->head->level + 1 < level)
        s->head = s->head->up;
    //将head的level调整到高于插入的level

    Node *node = getNewNode(x, level);
    Node *p = s->head;
    printf("insert begin\n");
    fflush(stdout);
    while (p->level != node->level)
        p = p->down;
    //将p指向与node的level一致的位置

    while (p)
    {
        while (p->next->key < node->key)
            p = p->next;
        node->next = p->next;
        p->next = node;
        p = p->down;
        node = node->down;
    }
}

void output(Skiplist *s)
{
    Node *p = s->head;
    int len = 0;
    for (int i = 0; i <= s->head->level; i++)
    {
        len += printf("%4d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");

    while (p->level > 0)
        p = p->down;
    while (p)
    {
        bool flag = (p->key != INT32_MIN && p->key != INT32_MAX);
        for (Node *q = p; flag && q; q = q->up)
        {
            printf("%4d", q->key);
        }
        if (flag)
            printf("\n");
        p = p->next;
    }
    printf("\n");
    return;
}

int main()
{
    srand(time(0));
    int x;
    Skiplist *s = getNewSkiplist(MAX_LEVEL);

    // insert
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        insert(s, x);
        output(s);
    }

    // find
    while (~scanf("%d", &x))
    {
        Node *p = find(s, x);
        if(x == -1)
            break;
        if (p)
        {
            printf("find result : key = %d, level =%d \n", p->key, p->level);
        }
        else
        {
            printf("find result : NULL\n");
        }
    }
    clearSkiplist(s);
    system("pause");
    return 0;
}