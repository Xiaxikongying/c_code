#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// AVL: 在二叉排序树上  任一节点对应的两棵子树的最大高度差为1

typedef struct Node
{
    int key;
    int h;
    struct Node *lchild, *rchild;
} Node;

Node *maintain(Node *root);

#define NIL (&__NIL)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define H(n) (n->h)
#define K(n) (n->key)


Node __NIL;  //虚拟空节点
__attribute((constructor)) //使下面的函数先于主函数执行
void init_NIL() 
{
    NIL->key = -1;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
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
}

void update_height(Node *root)
{

    H(root) = (H(root->lchild) > H(root->rchild) ? H(root->lchild) : H(root->rchild)) + 1;
    return;
}

Node *left_rotate(Node *root)
{
    printf("left rotate: %d\n", root->key);
    Node *new_root = root->rchild;
    root->rchild = new_root->lchild;
    new_root->lchild = root;

    update_height(root);
    maintain(new_root);
    return new_root;
}
Node *right_rotate(Node *root)
{
    printf("right rotate: %d\n", root->key);
    Node *new_root = root->lchild;
    root->lchild = new_root->rchild;
    new_root->rchild = root;
    
    update_height(root);
    maintain(new_root);
    return new_root;
}

const char *type_str[5] = {
    "",
    "maintain type : LL",
    "maintain type : LR",
    "maintain type : RR",
    "maintain type : RL"};

Node *maintain(Node *root)
{
    int type = 0;
    if (abs(H(root->lchild) - H(root->rchild)) <= 1)  //左右子树差值小于=1 不用调整
        return root;

    if (H(root->lchild) > H(root->rchild)) // L类型
    {
        type = 0;
        if (H(root->lchild->rchild) > H(root->lchild->lchild)) // LR类型
        {
            root->lchild = left_rotate(root->lchild); //若是LR类型 则先左旋  再右旋
            type++;                                   // type = 2  LR
        }
        root = right_rotate(root); //若是LL类型 则直接右旋
        type++;                    // type = 1  LR
    }
    else // R类型
    {
        type = 2;
        if (H(root->rchild->lchild) > H(root->rchild->rchild)) // RL类型
        {
            root->rchild = right_rotate(root->rchild); //若是RL类型 则先右旋  再左旋
            type++;                                    // type = 4 RL
        }
        root = left_rotate(root); //若是RR类型 则直接左旋
        type++;                   // type = 3 RR
    }

    printf("%s\n", type_str[type]);
    return root;
}

Node *insert(Node *root, int key)
{
    if (root == NIL)
        return getNewNode(key);
    if (key == root->key)
        return root;
    if (key < root->key)
        root->lchild = insert(root->lchild, key);
    else
        root->rchild = insert(root->rchild, key);
    update_height(root);
    return maintain(root);
}

Node *pre_node(Node *root)
{
    Node *temp = root->lchild;
    while (temp->lchild != NIL)
        temp = temp->lchild;
    return temp;
}

Node *erase(Node *root, int key)
{
    if (root == NIL)
        return root;

    if (key < root->key)
        root->lchild = erase(root->lchild, key);
    else if (key > root->key)
        root->rchild = erase(root->rchild, key);
    else
    {
        if (root->lchild == NIL || root->rchild == NIL) //度为 1 或 0
        {
            Node *temp = (root->lchild != NIL) ? root->lchild : root->rchild;
            free(root);
            return temp;
        }
        else //度为2时
        {
            Node *temp = pre_node(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_height(root);
    return maintain(root);
}

Node *find(Node *root, int key)
{
    if (root == NIL)
        return NIL;
    if (key == root->key)
        return root;

    if (key < root->key)
        return find(root->lchild,key);
    else
        return find(root->rchild, key);
}

void output(Node *root)
{
    if (root == NIL)
        return;
    printf("(%d[%d] | %d %d )\n", root->key, root->h, root->lchild->key, root->rchild->key);
    output(root->lchild);
    output(root->rchild);
    return;
}

int main()
{
#define MAX_OP 10
    srand(time(0));
    int x;
    Node *root = NIL;
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        printf("insert %d to avl tree\n", x);
        root = insert(root, x);
        output(root);
    }

    printf("\n\n");
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        printf("erase %d from avl tree\n", x);
        root = erase(root, x);
        output(root);
    }

    printf("\n\n");
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        printf("find %d in avl tree   %d\n", x, find(root, x) != NIL);
    }

    system("pause");
    return 0;
}
