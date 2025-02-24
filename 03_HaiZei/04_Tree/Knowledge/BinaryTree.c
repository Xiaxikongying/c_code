#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
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

Node *insertTree(Node *root, int key)
{
    if (root == NULL)
        return getNewNode(key);
    if (rand() % 2 == 1)
        root->lchild = insertTree(root->lchild, key);
    else
        root->rchild = insertTree(root->rchild, key);
    return root;
}

Node *queue[20];
int head, tail;
void bfs(Node *root)
{
    head = tail = 0;
    queue[tail++] = root;
    while (head < tail)
    {
        Node *node = queue[head];
        printf("\nnode: %d\n", node->key);
        if (node->lchild)
        {
            queue[tail++] = node->lchild;
            printf("\t%d->%d (left) \n", node->key, node->lchild->key);
        }

        if (node->rchild)
        {
            queue[tail++] = node->rchild;
            printf("\t%d->%d (right) \n", node->key, node->rchild->key);
        }
        head++;
    }
    return;
}

int tot = 0;
void dfs(Node *root)
{
    if (root == NULL)
        return;
    int start, end;
    tot++;
    start = tot;
    if (root->lchild)
        dfs(root->lchild);
    if (root->rchild)
        dfs(root->rchild);

    tot++;
    end = tot;
    printf("%d :[%d, %d]\n", root->key, start, end);
    return;
}

void pre_order(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    pre_order(root->lchild);
    pre_order(root->rchild);
    return;
}

int main()
{
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < 10; i++)
    {
        root = insertTree(root, rand() % 100);
    }
    bfs(root);
    printf("\n------------------------------------------------\n\n");
    dfs(root);

    printf("\n------------------------------------------------\n\n");
    pre_order(root);

    clear(root);
    system("pause");
    return 0;
}