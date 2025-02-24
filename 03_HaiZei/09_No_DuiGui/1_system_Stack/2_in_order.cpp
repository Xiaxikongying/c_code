#include <iostream>
#include <time.h>
#include <stack>
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
    while (temp->lchild)
        temp = temp->lchild;
    return temp;
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
    if (root == NULL) // code 0
        return;
    in_order(root->lchild);   // code 1
    printf("%d ", KEY(root)); // code 2
    in_order(root->rchild);   // code 3
    return;                   // code 4
}

struct Data
{
    Data(Node *root):root(root)
    {
        code = 0;
    }
    Node *root;
    int code;
};

void non_in_order(Node *root)
{
    stack<Data> s;
    Data d(root);
    s.push(d);
    while (!s.empty())
    {
        Data &cur = s.top();
        switch (cur.code)
        {
        case 0:
        {
            if (cur.root == NULL)
                s.pop();
            else
            {
                cur.code = 1;
            }
        }
        break;
        //---------------------------------------------
        case 1:
        {
            Data d(cur.root->lchild);
            cur.code = 2;
            s.push(d);
        }
        break;
        //---------------------------------------------
        case 2:
        {
            printf("%d ", cur.root->key);
            cur.code = 3;
        }
        break;
        //---------------------------------------------
        case 3:
        {
            Data d(cur.root->rchild);
            cur.code = 4;
            s.push(d);
        }
        break;
        //---------------------------------------------
        case 4:
            s.pop();
            break;
        }
    }
}

int main()
{
#define MAX_OP 10
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++)
    {
        int key = rand() % 100;
        //printf("insert key:%d to BST\n", key);
        root = insert(root, key);
    }

    printf("\nin_order :  \n");
    in_order(root);
    printf("\nnon_in_order  \n");
    non_in_order(root);
    printf("\n");

    system("pause");
    return 0;
}