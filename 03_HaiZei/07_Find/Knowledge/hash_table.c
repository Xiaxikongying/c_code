#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define swap(a, b)           \
    {                        \
        __typeof(a) __c = a; \
        a = b, b = __c;      \
    }

typedef struct Node
{
    char *s;
    struct Node *next;
} Node;

typedef struct HashTable
{
    Node *data;
    int size; //总大小
    int cnt;  //现有元素
} HashTable;

Node *getNewNode(const char *s)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->s = strdup(s);
    p->next = NULL;
    return p;
}

HashTable *getNewHashTable(int n)
{
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Node *)malloc(sizeof(Node) * n);
    h->cnt = 0;
    h->size = n;
    return h;
}

void clearHashTable(HashTable *h)
{
    if (h == NULL)
        return;
    for (int i = 0; i < h->size; i++)
    {
        Node *p = h->data[i].next, *q;
        while (p)
        {
            q = p->next;
            free(p->s);
            free(p);
            p = q;
        }
    }
    free(h->data);
    free(h);
}

int hash_func(const char *s)
{
    int seed = 131, h = 0;
    for (int i = 0; s[i]; i++)
    {
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;
}
void swapHashTable(HashTable *h1,HashTable *h2)
{
    swap(h1->data, h2->data);
    swap(h1->size, h2->size);
    swap(h1->cnt, h2->cnt);
    return;
}
bool insert(HashTable *h, const char *s);
void expend(HashTable *h)
{
    HashTable *new_h = getNewHashTable(h->size * 2);
    for (int i = 0; i < h->size; i++)
    {
        Node *p = h->data[i].next;
        while(p)
        {
            insert(new_h, p->s);
            p = p->next;
        }
    }
    swapHashTable(new_h, h);
    clearHashTable(new_h);
}

bool insert(HashTable *h, const char *s)
{
    if (h->cnt >= h->size * 2)
        expend(h);

    int hcode = hash_func(s);
    int ind = hcode % h->size;

    Node *p = getNewNode(s);
    p->next = h->data[ind].next;
    h->data[ind].next = p;
    //头插法

    h->cnt++;
    return true;
}

bool find(HashTable *h, const char *s)
{
    int hcode = hash_func(s);
    int ind = hcode % h->size;
    Node *p = h->data[ind].next;
    while (p)
    {
        if (strcmp(p->s, s))
            return true;
        p = p->next;
    }
    return false;
}

void output(HashTable *h)
{
    printf("\n\nHash Table(%d / %d) : \n", h->cnt, h->size);
    for (int i = 0; i < h->size; i++)
    {
        printf("%d : ", i);
        Node *p = h->data[i].next;
        while (p)
        {
            if (p)
                printf("%s -> ", p->s);
            p = p->next;
        }
        printf("\n");
    }
    return;
}

int main()
{
    srand(time(0));
    char s[100];
    HashTable *h = getNewHashTable(2);

    while (~scanf("%s", s))
    {
        if (strcmp(s, "end") == 0)
            break;
        insert(h, s);
    }
    output(h);

    while (~scanf("%s", s))
    {
        if (strcmp(s, "end"))
            break;
        printf("find(%s) = %d \n", s, find(h, s));
    }

    system("pause");
    return 0;
}
