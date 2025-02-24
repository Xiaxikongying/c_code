#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int key;
    int ltag, rtag; //当tag ==1时 对应的边是线索
                    //  tag == 0时  为边
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key)

{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->ltag = p->rtag = 0;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root)
{
    if (root == NULL)
        return;
    if (root->ltag == 0)
        clear(root->lchild);
    if (root->rtag == 0)
        clear(root->rchild);
    free(root);
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

void pre_order(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    if (root->ltag == 0)
        pre_order(root->lchild);
    if (root->rtag == 0)
        pre_order(root->rchild);
    return;
}

void in_order(Node *root)
{
    if (root == NULL)
        return;
    if (root->ltag == 0)
        in_order(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == 0)
        in_order(root->rchild);
    return;
}

void post_order(Node *root)
{
    if (root == NULL)
        return;
    if (root->ltag == 0)
        post_order(root->lchild);
    post_order(root->rchild);
    if (root->rtag == 0)
        printf("%d ", root->key);
    return;
}



Node *getNext(Node *root)
{
    if (root->rtag == 1)
        return root->rchild;
    while (root->ltag == 0 && root->lchild)
    {
        root = root->lchild;
    }
    return root;
}

int main()
{
    srand(time(0));
    Node *root = NULL;

    for (int i = 0; i < 8; i++)
    {
        root = insertTree(root, rand() % 100);
    }


    pre_order(root);
    printf("\n\n");
    in_order(root);
    printf("\n\n");
    post_order(root);

    clear(root);
    system("pause");
    return 0;
}