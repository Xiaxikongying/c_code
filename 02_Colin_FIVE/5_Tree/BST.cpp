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

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = key;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
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

// BST插入
Node *BST_insert(Node *root, int key)
{

    if (root == NULL)
        return getNewNode(key);

    if (root->value == key)
        return root;
    else if (root->value > key)
        root->lchild = BST_insert(root->lchild, key);
    else
        root->rchild = BST_insert(root->rchild, key);
    return root;
}

//插入2
void AddNode(Node **root, int val)
{
    Node *node = getNewNode(val);

    if (root == NULL)
        *root = node;

    Node *p = *root;
    while (p)
    {
        if (p->value > val)
        {
            if (p->lchild == NULL)
            {
                p->lchild = node;
                break;
            }
            p = p->lchild;
        }

        if (p->value < val)
        {
            if (p->rchild == NULL)
            {
                p->rchild = node;
                break;
            }
            p = p->rchild;
        }

        else
        {
            cout << "数据重复" << endl;
            break;
        }
    }
}

Node *CreatBST(int arr[], int len)
{
    if (len <= 0)
        return NULL;
    Node *root = NULL;
    for (int i = 0; i < len; i++)
    {
        AddNode(&root, arr[i]);
    }
    return root;
}

//找度为2节点的前驱
Node *pre_Node(Node *root)
{
    Node *temp = root->lchild;
    while (temp->rchild)
        temp = temp->rchild;
    return temp;
}

// BST递归删除
Node *BST_erase(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (root->value > key)
        root->lchild = BST_erase(root->lchild, key);
    else if (root->value < key)
        root->rchild = BST_erase(root->rchild, key);
    else
    {
        //度为0
        if (root->lchild == NULL && root->rchild == NULL)
        {
            free(root);
            return NULL;
        }

        //度为1
        else if (root->lchild == NULL || root->rchild == NULL)
        {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        }

        //度为2
        //找到前驱 或者 后继（中序遍历前后的值）代替度为2的地位
        //转化为 度为1 或 0 的问题
        else
        {
            Node *temp = pre_Node(root);
            root->value = temp->value;
            root->lchild = BST_erase(root->lchild, temp->value);
        }
    }
    return root;
}

//删除2
void Search(Node *root, int val, Node **del, Node **Father)
{
    while (root)
    {
        if (root->value == val)
        {
            *del = root;
            return;
        }
        else if (root->value > val)
        {
            *Father = root;
            root = root->lchild;
        }
        else
        {
            *Father = root;
            root = root->rchild;
        }
    }
    if (root == NULL)
        *Father == NULL;
}

void erase_Node(Node **root, int val)
{
    if (*root == NULL)
        return;
    Node *Father = NULL;
    Node *p = NULL;
    Search(*root, val, &p, &Father);
    if (p == NULL)
        return;

    if (p->lchild && p->rchild) // 2个孩子
    {
        p->value = pre_Node(p)->value;
        Search(p->lchild, p->value, &p, &Father);
    }

    //删除的是根的话
    if (Father == NULL)
    {
        *root = (p->lchild ? p->lchild : p->rchild);
        free(p);
        return;
    }

    // 0或1个孩子
    if (Father->lchild == p)
        Father->lchild = (p->lchild ? p->lchild : p->rchild);
    else
        Father->rchild = (p->lchild ? p->lchild : p->rchild);
    free(p);
    p = NULL;
    return;
}
Node *head = NULL;
Node *tail = NULL;
//将BST转换为双向链表
void Double_List(Node *root)
{
    if (root == NULL)
        return;
    // lchild 为前驱   rchild 为next
    Double_List(root->lchild);
    if (head == NULL)
        head = root;
    else
    {
        tail->rchild = root;
        root->lchild = tail;
    }
    tail = root;
    Double_List(root->rchild);
    return;
}
void Double_List1(Node *root, Node **head, Node **tail)
{
    if (root == NULL)
        return;
    // lchild 为前驱   rchild 为next
    Double_List1(root->lchild, head, tail);
    if (*head == NULL)
        *head = root;
    else
    {
        (*tail)->rchild = root;
        root->lchild = *tail;
    }
    *tail = root;
    Double_List1(root->rchild, head, tail);
    return;
}

int main()
{
    Node *root = NULL;
    int a;
    // 5 4 7 2 1 3 6 8
    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        root = BST_insert(root, a);
    }
/*
    cout << "中序遍历 : ";
    in_order(root);
    cout << endl;

    cout << "要删除的数字是:";
    while (cin >> a)
    {
        cout << endl;
        erase_Node(&root, a);
        cout << "中序遍历 : ";
        in_order(root);
        cout << endl;
    }
*/  
        
        Double_List(root);
        Node *p = head;
        while (p)
        {
            cout << p->value << " ";
            p = p->rchild;
        }
        cout << endl;
    
    system("pause");
    return 0;
}