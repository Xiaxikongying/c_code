#include <iostream>
#include <stack>
#include <queue>
#include <time.h>
using namespace std;

typedef struct Node
{
    int value;
    struct Node *lchild, *rchild;
} Node;

Node *CreatNode()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->value = 1;

    root->lchild = (Node *)malloc(sizeof(Node));
    root->rchild = (Node *)malloc(sizeof(Node));
    root->lchild->value = 2;
    root->rchild->value = 3;

    root->lchild->lchild = (Node *)malloc(sizeof(Node));
    root->lchild->rchild = (Node *)malloc(sizeof(Node));
    root->rchild->lchild = (Node *)malloc(sizeof(Node));
    root->rchild->rchild = (Node *)malloc(sizeof(Node));
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

void pre_order(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    pre_order(root->lchild);
    pre_order(root->rchild);
    return;
}
void in_order(Node *root)
{
    if (root == NULL)
        return;
    in_order(root->lchild);
    printf("%d ", root->value);
    in_order(root->rchild);
    return;
}

void post_order(Node *root)
{
    if (root == NULL)
        return;
    post_order(root->lchild);
    post_order(root->rchild);
    printf("%d ", root->value);
    return;
}

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = key;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

void __pre_insert(Node *&root, int i)
{
    if (i == 0)
        return;
    Node *temp = getNewNode(i);
    if (root == NULL)
    {
        root = temp;
        return;
    }
    Node *p = root;
    while (p)
    {
        if (p->value == i)
            return;
        if (p->value > i)
        {
            if (p->lchild)
                p = p->lchild;
            else
                p->lchild = temp;
        }

        else
        {
            if (p->rchild)
                p = p->rchild;
            else
                p->rchild = temp;
        }
    }
    return;
}

// BST插入
void pre_insert(Node *&root, int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        __pre_insert(root, arr[i]);
    }
}

//随机插入
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

// Teacher的插入
void CreatTree(Node **root)
{
    int num;
    cout << "请输入数值" << endl;
    cin >> num;

    if (num == 0)
        return;

    *root = getNewNode(num);

    CreatTree(&(*root)->lchild);
    CreatTree(&(*root)->rchild);
}

//满二叉树 CBT
Node *CreatCBT(int *arr, int len)
{
    Node *root = NULL;
    root = (Node *)malloc(sizeof(Node) * len);
    for (int i = 0; i < len; i++)
    {
        root[i].value = arr[i];
        root[i].lchild = root[i].rchild = NULL;
    }

    for (int i = 0; i < len / 2; i++)
    {
        if (2 * i + 1 < len)
            root[i].lchild = &root[2 * i + 1];
        if (2 * i + 2 < len)
            root[i].rchild = &root[2 * i + 2];
    }
    return root;
}

//------------------------------------------------------------------

void New_pre_order(Node *root)
{
    stack<Node *> s;
    while (1)
    {
        while (root != NULL)
        {
            printf("%d ", root->value);
            s.push(root);
            root = root->lchild;
        }
        if (s.empty())
            break;

        root = s.top();
        s.pop();
        root = root->rchild;
    }
    return;
}

void New_in_order(Node *root)
{
    stack<Node *> s;
    while (1)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->lchild;
        }
        if (s.empty())
            break;

        root = s.top();
        printf("%d ", root->value);
        s.pop();
        root = root->rchild;
    }
    return;
}

void New_post_order(Node *root)
{
    stack<Node *> s;
    Node *temp = NULL;
    while (1)
    {
        while (root != NULL)
        {
            if (root == temp)
                break;
            s.push(root);
            root = root->lchild;
        }
        if (s.empty())
            break;

        root = s.top();
        if (root->rchild == NULL || root->rchild == temp)
        {
            printf("%d ", root->value);
            temp = s.top();
            s.pop();
        }
        else
            root = root->rchild;
    }
    return;
}

//层序遍历
void CengXu_order(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        if (q.front()->lchild != NULL)
            q.push(q.front()->lchild);
        if (q.front()->rchild != NULL)
            q.push(q.front()->rchild);
        printf("%d ", q.front()->value);
        q.pop();
    }
}

//分层层序遍历
void New_CengXu_order(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    int cnt;

    while (!q.empty())
    {
        cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            if (q.front()->lchild != NULL)
                q.push(q.front()->lchild);
            if (q.front()->rchild != NULL)
                q.push(q.front()->rchild);
            printf("%d ", q.front()->value);
            q.pop();
        }
        cout << endl;
    }
    return;
}

int main03()
{
    Node *root = NULL;
    CreatTree(&root);
    pre_order(root);
    printf("\n");
    system("pause");
    return 0;
}

int main()
{
    Node *root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0};
    int len = sizeof(arr) / sizeof(int);
    pre_insert(root, arr, len);
    New_post_order(root);
    cout << endl;
    post_order(root);
    system("pause");
    return 0;
}
/*
int main01()
{
    Node *root = NULL;

    Node *root1 = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0};
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < len / 2; i++)
        root1 = pre_insert(root1, arr, len, 0);

   pre_order(root);
   cout << endl;
   New_pre_order(root);
   cout << endl;


    int i = 10;
    srand(time(0));
    while (--i)
        root = insertTree(root, i);
    pre_order(root);
    cout << endl;
    New_pre_order(root);
    cout << endl;

    in_order(root);
    cout << endl;
    New_in_order(root);
    cout << endl;

    post_order(root);
    cout << endl;
    New_post_order(root);
    cout << endl;
    noResLast(root);
    cout << endl;

    CengXu_order(root);
    cout << endl;

    New_CengXu_order(root1);
    cout << endl;

    system("pause");
    return 0;
}
*/
/*
 Node *root = CreatNode();

 printf("前序遍历: ");
 pre_order(root);
 printf("\n");

 printf("中序遍历: ");
 in_order(root);
 printf("\n");

 printf("后序遍历: ");
 post_order(root);
 printf("\n");
 */