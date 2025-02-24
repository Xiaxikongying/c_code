#include <stdio.h>
#include <stdlib.h>

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

Node *insertTree(Node *root, int len, int key)
{

    if (root == NULL)
    {
        if (key > len)
            return root;
        printf("%d \n", key);
        return getNewNode(key);
    }

    root->lchild = insertTree(root->lchild, len, 2 * key);
    root->rchild = insertTree(root->rchild, len, 2 * key + 1);

    return root;
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
    scanf("%d", &n);
    Node *root = NULL;
    
    for (int i = 0; i < n / 2; i++)
        root = insertTree(root, n, 1);

    in_order(root);
    printf("\n");
    clear(root);
    system("pause");
    return 0;
}
