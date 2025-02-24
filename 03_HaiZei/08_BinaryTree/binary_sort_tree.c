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
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return getNewNode(key);
    if (key == root->key)
        return root;
    if (key < root->key)
        root->lchild = insert(root->lchild, key); //一直向左找 直到左为空
    else
        root->rchild = insert(root->rchild, key);
    return root; //返回根节点
}

Node *pre_Node(Node *root)
{ //度为2的点找前驱
    Node *temp = root->lchild;
    while (temp->rchild)
        temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->lchild = erase(root->lchild, key);
    else if (key > root->key)
        root->rchild = erase(root->rchild, key);
    else //找到key值对应的节点
    {
        if (root->lchild == NULL && root->rchild == NULL)
        { //度为0时
            free(root);
            return NULL;
        }
        else if (root->lchild == NULL || root->rchild == NULL)
        { //度为1时
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        }
        else
        { //度为2时
            Node *temp = pre_Node(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root; //返回根节点
}

#define KEY(n) (n ? n->key : -1)
void output(Node *root)
{
    //前序遍历
    if (root == NULL)
        return;
    printf("(%d: %d, %d)\n",
           KEY(root), KEY(root->lchild), KEY(root->rchild));
    output(root->lchild);
    output(root->rchild);
    return;
}

void in_order(Node *root)
{
    if (root == NULL)
        return;
    in_order(root->lchild);
    printf("%d ", KEY(root));
    in_order(root->rchild);
    return;
}

int main()
{
#define MAX_OP 10
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++)
    {
        int key = rand() % 100;
        printf("insert key:%d to BST\n", key);
        root = insert(root, key);
    }
    printf("\n前序遍历:  \n");
    output(root);
    printf("\n中序遍历:  \n");
    in_order(root);
    printf("\n");

    int x;
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
            break;
        printf("erase %d from BST\n", x);
        root = erase(root, x);
        in_order(root);
        printf("\n");
    }

    system("pause");
    return 0;
}