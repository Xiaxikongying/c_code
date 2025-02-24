#include <iostream>
using namespace std;

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

void insertTree(Node *&root, int len, int key)
{
    if (root == NULL)
    {
        if (key > len)
            return;
        root = getNewNode(key);
    }

    insertTree(root->lchild, len, 2 * key);
    insertTree(root->rchild, len, 2 * key + 1);
}

void in_order(Node *root)
{
    if (root == NULL)
        return;
    in_order(root->lchild);
    printf("%d ", root->key);
    in_order(root->rchild);
    return;
}

void clear(Node *root)
{
    if (root == NULL)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

int main()
{
    int n;
    while (scanf("%d", &n))

    {
        Node *root = NULL;
        insertTree(root, n, 1);
        in_order(root);
        printf("\n");
        clear(root);
    }

    return 0;
}
