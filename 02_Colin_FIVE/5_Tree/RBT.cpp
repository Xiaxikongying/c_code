#include <iostream>
using namespace std;

#define RED 0
#define BLACK 1
typedef struct Node
{
    int val;
    int color;
    struct Node *lchild, *rchild;
} Node;

Node * const NIL = new Node{-1, 1, NIL, NIL};

Node *getNewNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->color = RED; // 0表示红色
    p->lchild = p->rchild = NIL;
    return p;
}

Node *left_rotate(Node *root)
{
    Node *new_root = root->rchild;
    root->rchild = new_root->lchild;
    new_root->lchild = root;
    return new_root;
}

Node *right_rotate(Node *root)
{
    Node *new_root = root->lchild;
    root->lchild = new_root->rchild;
    new_root->rchild = root;
    return new_root;
}

bool if_REDchild(Node *root)
{
    if (root->lchild->color == RED || root->rchild->color == RED)
        return true;
    return false;
}

Node *insert_adjust(Node *root)
{
    int flag = 0;
    if (root->lchild->color == RED && if_REDchild(root->lchild))
        flag = 1;
    if (root->rchild->color == RED && if_REDchild(root->rchild))
        flag = 2;

    if (flag == 0) //没有冲突
        return root;

    if (root->lchild->color == RED && root->rchild->color == RED) //叔叔节点为红色
    {
        root->color = RED;
        root->lchild->color = BLACK;
        root->rchild->color = BLACK;
        return root;
    }

    if (flag == 1) //叔父节点为黑色  并且左子树需要调整  // LL  LR型调整
    {
        if (root->lchild->rchild->color == RED)       // LR型问题
            root->lchild = left_rotate(root->lchild); //将LR变成LL型
        root = right_rotate(root);                    // LL型问题
    }
    if (flag == 2) //右子树需要调整   RR  RL型调整
    {
        if (root->rchild->lchild->color == RED)        //如果if成立
            root->rchild = right_rotate(root->rchild); //将RL型变为RR型
        root = left_rotate(root);                      // RR型
    }

    root->color = RED;
    root->lchild->color = BLACK;
    root->rchild->color = BLACK;
    return root;
}

Node *insert(Node *root, int v)
{
    if (root == NIL)
        return getNewNode(v);
    if (root->val == v)
        return root;
    if (root->val > v)
        root->lchild = insert(root->lchild, v);
    if (root->val < v)
        root->rchild = insert(root->rchild, v);

    return insert_adjust(root);
}

Node *__insert(Node *root, int val)
{
    root = insert(root, val);
    root->color = BLACK;
    return root;
}

void pre_order(Node *root)
{
    if (root == NIL)
        return;
    printf("color: %d    ", root->color);
    printf("val:   %d\n", root->val);
    pre_order(root->lchild);
    pre_order(root->rchild);
    return;
}

void in_order(Node *root)
{
    if (root == NIL)
        return;
    in_order(root->lchild);
    printf("color: %d    ", root->color);
    printf("val:   %d\n", root->val);
    in_order(root->rchild);
    return;
}

int main()
{
    Node *root = NIL;
    int a;
    for (int i = 0; i < 5; i++)
    {
        cin >> a;
        root = __insert(root, a);
    }
    printf("pre_order:\n");
    pre_order(root);
    printf("\n-----------------------------\n\nin_order:\n");
    in_order(root);

    system("pause");
    return 0;
}