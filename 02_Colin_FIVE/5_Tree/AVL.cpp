#include <iostream>
#include <stack>
#include <queue>
#include <time.h>
using namespace std;

typedef struct Node
{
    int value;
    struct Node *lchild, *rchild, *father;
} Node;

Node *CreatNode()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->value = 1;
    root->father = NULL;

    root->lchild = (Node *)malloc(sizeof(Node));
    root->rchild = (Node *)malloc(sizeof(Node));
    root->lchild->father = root;
    root->rchild->father = root;
    root->lchild->value = 2;
    root->rchild->value = 3;

    root->lchild->lchild = (Node *)malloc(sizeof(Node));
    root->lchild->rchild = (Node *)malloc(sizeof(Node));
    root->rchild->lchild = (Node *)malloc(sizeof(Node));
    root->rchild->rchild = (Node *)malloc(sizeof(Node));
    root->lchild->lchild->father = root->lchild;
    root->lchild->rchild->father = root->lchild;
    root->rchild->lchild->father = root->rchild;
    root->rchild->rchild->father = root->rchild;

    root->lchild->lchild->value = 4;
    root->lchild->rchild->value = 5;
    root->rchild->lchild->value = 6;
    root->rchild->rchild->value = 7;

    root->lchild->lchild->lchild = NULL;
    root->lchild->lchild->rchild = NULL;
    root->lchild->rchild->lchild = NULL;
    root->lchild->rchild->rchild = NULL;

    root->rchild->lchild->lchild = NULL;
    root->rchild->lchild->rchild = NULL;
    root->rchild->rchild->lchild = NULL;
    root->rchild->rchild->rchild = NULL;

    return root;
}

void Right_rotate(Node **root)
{
    if ((*root)->lchild == NULL || (*root) == NULL)
        return;
    Node *new_root = (*root)->lchild;
    if (new_root->rchild) //判断新根节点是否右左孩子
        new_root->rchild->father = *root;

    (*root)->lchild = new_root->rchild;
    new_root->rchild = (*root);

    if ((*root)->father) //原根节点是否有父亲
    {
        if ((*root)->father->lchild == (*root))
            (*root)->father->lchild = new_root;
        else
            (*root)->father->rchild = new_root;
    }

    new_root->father = (*root)->father;
    (*root)->father = new_root;

    (*root) = new_root;
}

void Left_rotate(Node **root)
{
    if ((*root) == NULL || (*root)->rchild == NULL)
        return;
    Node *new_root = (*root)->rchild;
    if (new_root->lchild) //判断新根节点是否左左孩子
        new_root->lchild->father = *root;

    (*root)->rchild = new_root->lchild;
    new_root->lchild = (*root);

    if ((*root)->father) //原根节点是否有父亲
    {
        if ((*root)->father->lchild == (*root))
            (*root)->father->lchild = new_root;
        else
            (*root)->father->rchild = new_root;
    }

    new_root->father = (*root)->father;
    (*root)->father = new_root;

    (*root) = new_root;
}

void pre_order(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    pre_order(root->lchild);
    pre_order(root->rchild);
    return;
}

void Left_rotate1(Node *&root)
{
    if (root == NULL || root->rchild == NULL)
        return;
    Node *new_root = root->rchild;
    Node *Father = root->father;

    //新根节点的左孩子
    if (new_root->lchild)
        new_root->rchild->father = root;
    root->rchild = new_root->lchild; //如果新根没有左孩子，则原根右孩子赋为空

    //新根节点
    if (Father)
    {
        new_root->father = Father;
        Father->lchild == root ? Father->lchild = new_root : Father->rchild = new_root;
    }
    new_root->lchild = root;
    //原根节点
    root->father = new_root;
    //还原根节点
    root = new_root;
}

void Right_rotate1(Node *&root)
{
    if (root == NULL || root->lchild == NULL)
        return;
    Node *new_root = root->lchild;
    Node *Father = root->father;

    //新根节点的右孩子
    if (new_root->rchild)
        new_root->rchild->father = root;
    root->lchild = new_root->rchild; //如果新根没有右孩子，则原根右孩子赋为空

    //新根节点
    if (Father)
    {
        new_root->father = Father;
        Father->lchild == root ? Father->lchild = new_root : Father->rchild = new_root;
    }
    new_root->rchild = root;
    //原根节点
    root->father = new_root;

    //还原根节点
    root = new_root;
}

int main()
{
    Node *root = CreatNode();
    pre_order(root);
    cout << endl;
    // Right_rotate(&(root));
    Right_rotate1(root);
    // Left_rotate(&(root));
    pre_order(root);
    cout << endl;

    system("pause");
    return 0;
}
/*
void Left_rotate(Node *&root)
{
    if (root == NULL || root->rchild == NULL)
        return;
    Node *new_root = root->rchild;
    Node *Father = root->father;

    //新根节点的左孩子
    if (new_root->lchild)
        new_root->rchild->father = root;
    root->rchild = new_root->lchild;  //如果新根没有左孩子，则原根右孩子赋为空

    //新根节点
    if (Father)
    {
        new_root->father = Father;
        Father->lchild == root ? Father->lchild = new_root : Father->rchild = new_root;
        new_root->lchild = root;
    }
    //原根节点
    root->father = new_root;
}

void Right_rotate(Node *&root)
{
    if (root == NULL || root->rchild == NULL)
        return;
    Node *new_root = root->lchild;
    Node *Father = root->father;

    //新根节点的右孩子
    if (new_root->rchild)
        new_root->rchild->father = root;
    root->lchild = new_root->rchild; //如果新根没有右孩子，则原根右孩子赋为空

    //新根节点
    if (Father)
    {
        new_root->father = Father;
        Father->lchild == root ? Father->lchild = new_root : Father->rchild = new_root;
        new_root->rchild = root;
    }
    //原根节点
    root->father = new_root;
}
*/
