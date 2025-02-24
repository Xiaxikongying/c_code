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

typedef struct Node
{
    struct Node *lchild, *rchild;
    char ch;
    int freq;
} Node;
typedef struct Heap
{
    Node **__data, **data;
    int n, size;
} Heap;

Heap *getNewHeap(int size)
{
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->__data = (Node **)malloc(sizeof(Node *) * size);
    h->data = h->__data - 1;
    h->size = size;
    h->n = 0;
    return h;
}
void clearHeap(Heap *h)
{
    if (h == NULL)
        return;
    free(h->__data);
    free(h);
    return;
}

int fullHeap(Heap *h)
{
    return h->n == h->size;
}
int emptyHeap(Heap *h)
{
    return h->n == 0;
}
Node *top(Heap *h)
{
    if (emptyHeap(h))
        return NULL;
    return h->data[1];
}

void up_updata(Heap *h, int i)
{
    while (i > 1 && h->data[i]->freq < h->data[father(i)]->freq)
    {
        swap(h->data[i], h->data[father(i)]);
        i = father(i);
    }
    return;
}
void down_updata(Heap *h, int i)
{
    while (left(i) <= h->n)
    {
        int ind = i, l = left(i), r = right(i);
        if (h->data[l]->freq < h->data[ind]->freq)
            ind = l;
        if (r <= h->n && h->data[r]->freq < h->data[ind]->freq)
            ind = r;
        if (i == ind)
            break;
        swap(h->data[i], h->data[ind]);
        i = ind;
    }
    return;
}

int pushHeap(Heap *h, Node *n)
{
    if (fullHeap(h))
        return 0;
    h->n += 1;
    h->data[h->n] = n;
    up_updata(h, h->n);
    return 1;
}

int popHeap(Heap *h)
{
    if (emptyHeap(h))
        return 0;
    h->data[1] = h->data[h->n];
    h->n -= 1;
    down_updata(h, 1);
    return 1;
}

Node *getNewNode(int freq, char ch)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->rchild = p->lchild = NULL;
    return p;
}
void clear(Node *root)
{
    if (root == NULL)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
void swap_node(Node **node_arr, int min, int j)
{
    Node *temp = node_arr[min];
    node_arr[min] = node_arr[j];
    node_arr[j] = temp;
}

int find_min_node(Node **node_arr, int n)
{
    int min = 0;
    for (int j = 1; j <= n; j++)
    {
        if (node_arr[min]->freq > node_arr[j]->freq)
            min = j;
    }
    return min;
}

Node *buildHaffmanTree(Node **node_arr, int n)
{
    Heap *h = getNewHeap(n);
    for (int i = 0; i < n; i++)
    {
        pushHeap(h, node_arr[i]);
    }

    for (int i = 1; i < n; i++)
    {
        Node *node1 = top(h); //获得第一个最小节点
        popHeap(h);
        Node *node2 = top(h); //获得第二个最小节点
        popHeap(h);

        int f = node1->freq + node2->freq;
        Node *node3 = getNewNode(f, 0); // 合并两个节点
        node3->lchild = node1;
        node3->rchild = node2;
        pushHeap(h, node3);
    }
    Node *ret = top(h);
    clearHeap(h);
    return ret;
}

void extractHaffmanCode(Node *root, char buff[], int k)
{
    buff[k] = 0;
    if (root->rchild == NULL && root->lchild == NULL)
    {
        printf("%c :%s\n", root->ch, buff);
        return;
    }

    buff[k] = '0';
    extractHaffmanCode(root->lchild, buff, k + 1);

    buff[k] = '1';
    extractHaffmanCode(root->rchild, buff, k + 1);
    return;
}

int main()
{

    int n;
    scanf("%d", &n);
    char s[10];
    int freq;

    Node **node_arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", s, &freq);
        node_arr[i] = getNewNode(freq, s[0]);
    }
    printf("---------------------------------------------------\n\n");
    Node *root = buildHaffmanTree(node_arr, n);
    char buff[1000];
    extractHaffmanCode(root, buff, 0);
    clear(root);
    system("pause");
    return 0;
}