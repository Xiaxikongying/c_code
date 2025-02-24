#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define KEY(n) (n ? n->key : -1)

// 广义表eg:  A(B(D,) ,C(,E))
// 二叉树 与 广义表 的相互转换

typedef struct Node
{
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getnewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root)
{
    if (root = NULL)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return getnewNode(key);
    if (rand() % 2)
        root->lchild = insert(root->lchild, key);
    else
        root->rchild = insert(root->rchild, key);
    return root;
}

Node *getRandomBinaryTree(int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, rand() % 100);
    }
    return root;
}

//____________________________________________二叉树----->广义表__________________________________________
char buff[1000];
int len = 0;

void __serialize(Node *root)
{
    if (root == NULL)
        return;
    len += snprintf(buff + len, 100, "%d", root->key);
    // snprintf --->  将 root->key 的值输出到buff的后面   100为最大距离
    if (root->lchild == NULL && root->rchild == NULL)
        return;
    //为叶子节点时 不用输入括号
    else
        len += snprintf(buff + len, 100, "(");
    __serialize(root->lchild);

    if (root->rchild)
    {
        len += snprintf(buff + len, 100, ",");
        __serialize(root->rchild);
    }
    len += snprintf(buff + len, 100, ")");
    return;
}

void serialize(Node *root)
{
    memset(buff, 0, sizeof(buff));
    len = 0;
    __serialize(root);
    return;
}

void print(Node *root)
{
    printf("%d(%d, %d)\n",
           KEY(root),
           KEY(root->lchild),
           KEY(root->rchild));

    return;
}
void output(Node *root)
{
    if (root == NULL)
        return;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return;
}

//___________________________________广义表----->二叉树_____________________________________
#define MAX_NODE 10
Node *deserialize(char *buff, int len)
{
    Node **s = (Node **)malloc(sizeof(Node *) * MAX_NODE);
    int top = -1, flag = 0; // flag0 表示左子树   1表示右子树
    int scode = 0;          // scode 是状态机
    /*
    0---> 任务分发
    1--->关键字 4 2 5 1 3之类的
    2---> (
    3---> ,
    4---> )
    */
    Node *p = NULL; //指向最后一个节点
    Node *root = NULL;
    for (int i = 0; buff[i]; i++)
    {
        switch (scode)
        {
        case 0:
        {
            if (buff[i] >= '0' && buff[i] <= '9')
                scode = 1;
            else if (buff[i] == '(')
                scode = 2;
            else if (buff[i] == ',')
                scode = 3;
            else
                scode = 4;
            i--;
        }
        break;

        case 1: //根据关键字形成新的节点
        {
            int key = 0;
            while (buff[i] >= '0' && buff[i] <= '9')
            {
                key = key * 10 + (buff[i] - '0');
                //将 一个字符 以int方式存入num
                i++;
            }
            p = getnewNode(key);
            if (top >= 0) //有栈顶
            {
                if (flag == 0)
                    s[top]->lchild = p;
                if (flag == 1)
                    s[top]->rchild = p;
            }
            i--;
            scode = 0;
        }
        break;

        case 2: // 遇到 ( 将上一个新节点压入栈内
        {
            s[++top] = p;
            flag = 0;
            scode = 0;
        }
        break;

        case 3: //遇到 ,
        {
            flag = 1;
            scode = 0;
        }
        break;

        case 4: //遇到 ) 弹出上一个新节点
        {
            root = s[top];
            top--;
            // root 是最后一个弹出栈的节点
            scode = 0;
        }
        break;
        }
    }
    return root;
}

int main()
{
    srand(time(0));
    Node *root = getRandomBinaryTree(10);
    //__________________二叉树----->广义表____________________
    output(root);

    serialize(root);
    printf("Buff[] : %s\n", buff);

    //__________________广义表----->二叉树____________________

    Node *new_root = deserialize(buff, len);
    output(new_root);
    system("pause");
    return 0;
}