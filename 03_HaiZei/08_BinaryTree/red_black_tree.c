#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1
#define DBLACK 2
#define NIL (&__NIL)
#define K(n) (n->key)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define C(n) (n->color)

typedef struct Node
{
    int key, color; // 0 为红色   1为黑色  2为双重黑
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
// NIL初始化
__attribute((constructor)) void init_NIL()
{
    NIL->key = -1;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

void clear(Node *root)
{
    if (root == NIL)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

bool has_red_node(Node *root) //有没有红孩儿
{
    return (root->lchild->color == RED || root->rchild->color == RED);
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

Node *insert_maintain(Node *root)
{
    int flag = 0;
    if (root->lchild->color == RED && has_red_node(root->lchild)) //左子树有两个红相连
        flag = 1;                                                 //冲突在左子树
    if (root->rchild->color == RED && has_red_node(root->rchild)) //右子树有两个红相连
        flag = 2;                                                 //冲突在右子树

    if (flag == 0) //无冲突
        return root;

    //插入调整情况一      叔叔节点为红色时
    if (C(L(root)) == RED && C(R(root)) == RED) //左右子节点都是红  即 叔 和 父 节点都为红色
    {                                           //红色上浮
        C(root) = RED;                          // root 变为红
        C(R(root)) = C(L(root)) = BLACK;        // root的子节点全变为黑
        return root;
    }

    //插入情况二      叔叔节点为黑色时
    if (flag == 1) //左子树有2个红色相连
    {
        if (root->lchild->rchild->color == RED) // LR为红
        {
            L(root) = left_rotate(L(root)); //  LR(1)
        }
        root = right_rotate(root); // LL(1)为红色  LR(2)
    }
    else if (flag == 2)
    {
        if (root->rchild->lchild->color == RED) // RL为红
        {
            R(root) = right_rotate(R(root)); //  RL(1)
        }
        root = left_rotate(root); // RR(1)为红色   RL(2)
    }

    //红色上浮
    C(root) = RED;
    C(L(root)) = C(R(root)) = BLACK;
    return root;
}

Node *__insert(Node *root, int key)
{
    if (root == NIL)
        return getNewNode(key);
    if (root->key == key)
        return root;
    if (key < root->key)
        root->lchild = __insert(root->lchild, key);
    else
        root->rchild = __insert(root->rchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key)
{
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

Node *pre_node(Node *root) //找两个节点的前驱
{
    Node *temp = root->lchild;
    while (temp->rchild != NIL)
        temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root)
{
    if (root->lchild->color != DBLACK && root->rchild->color != DBLACK)
        return root; //无双重黑节点

    if (has_red_node(root)) //有双重黑 且兄弟节点是红色 ----->调整情况四
    {
        root->color = RED;              //原根节点变为红色
        if (root->lchild->color == RED) //左子树为红  右双黑
        {
            root = right_rotate(root);
            root->rchild = erase_maintain(root->rchild);
        }

        else if (root->rchild->color == RED) //右子树为红  左双黑
        {
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);
        }

        root->color = BLACK; //新根节点变为黑色
        return root;
    }

    //有双重黑 且兄弟节点是红色 ----->调整情况一二三
    if (root->lchild->color == DBLACK && !has_red_node(root->rchild) ||
        root->rchild->color == DBLACK && !has_red_node(root->lchild))
    {
        //调整情况一   一边双黑  兄弟节点和其子节点都是黑
        root->color++;
        root->lchild--;
        root->rchild--;
        return root;
    }

    //调整情况二三
    if (root->rchild->color == DBLACK) // L类型  右边双黑  左边单黑
    {
        root->rchild->color = BLACK;
        if (root->lchild->lchild != RED) // LR类型
        {
            root->lchild = left_rotate(root->lchild); // LR(1)
        }
        root->lchild->color = root->color;                 //新根节点颜色变成旧根节点的颜色
        root = right_rotate(root);                         // LL(1)  且  LR(2)
        root->lchild->color = root->rchild->color = BLACK; //新根子节点变黑
    }

    else if (root->lchild->color == DBLACK) // R类型  左边双黑
    {
        root->lchild->color = BLACK;
        if (root->rchild->rchild != RED) // RL类型
        {
            root->rchild = right_rotate(root->rchild); // RL(1)
        }
        root->rchild->color = root->color;                 //新根节点颜色变成旧根节点的颜色
        root = left_rotate(root);                          // RR(1)  且  RL(2)
        root->lchild->color = root->rchild->color = BLACK; //新根子节点变黑
    }
    return root;
}

Node *__erase(Node *root, int key)
{
    if (root == NIL)
        return root;
    if (key < root->key)
        root->lchild = __erase(root->lchild, key);
    else if (key > root->key)
        root->rchild = __erase(root->rchild, key);

    else
    {
        if (root->lchild == NIL || root->rchild == NIL) //度为0或1
        {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color; //同时兼容三种情况
            free(root);
            return temp;
            //该段代码是删除度为0或1的节点
            // 0红  直接删除 temp = NIL + 0  颜色不变
            // 1红   不存在该类节点
            // 0黑   直接删除 temp = NIL +1  --->DNIL 双重黑空节点
            // 1黑  的子节点只能是红色，不可能是黑色
            //     删除后 红色节点变黑接替父节点的位置
        }
        //度为2
        Node *temp = pre_node(root);
        root->key = temp->key;
        root->lchild = __erase(root->lchild, temp->key);
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key)
{
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void output(Node *root)
{
    if (root == NIL)
        return;
    printf("(%d| %d; %d, %d)\n",
           C(root), K(root), K(L(root)), K(R(root)));
    output(root->lchild);
    output(root->rchild);
    return;
}

int main()
{
#define MAX_OP 10
    srand(time(0));
    Node *root = NIL;
    for (int i = 0; i < MAX_OP; i++)
    {
        int x;
        x = rand() % 100;
        printf("\ninsert %d to red black tree : \n", x);
        root = insert(root, x);
        output(root);
    }

    int x;
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        printf("\nerase %d from red black tree\n\n", x);
        root = erase(root, x);
        output(root);
    }

    system("pause");
    return 0;
}