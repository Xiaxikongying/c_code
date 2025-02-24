#include <iostream>
using namespace std;

#define RED 0
#define BLACK 1
typedef struct Node
{
    int val;
    int color;
    struct Node *lchild, *rchild, *father;
} Node;

Node *ROOT = NULL;

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = key;
    p->color = RED;
    p->lchild = p->rchild = p->father = NULL;
    return p;
}

void left_rotate(Node *pTree)
{
    if (pTree == NULL || pTree->rchild == NULL)
        return;
    // mark就是new_root  pTree是root
    Node *pMark = pTree->rchild;
    pTree->rchild = pMark->lchild;
    pMark->lchild = pTree;

    if (pTree->father)
    {
        if (pTree == pTree->father->lchild)
            pTree->father->lchild = pMark;
        else
            pTree->father->rchild = pMark;
    }
    else
        ROOT = pMark;

    if (pTree->rchild)
        pTree->rchild->father = pTree;
    pMark->father = pTree->father;
    pTree->father = pMark;
}

void right_rotate(Node *pTree)
{
    if (pTree == NULL || pTree->lchild == NULL)
        return;
    Node *pMark = pTree->lchild;
    pTree->lchild = pMark->rchild;
    pMark->rchild = pTree;

    if (pTree->father)
    {
        if (pTree == pTree->father->lchild)
            pTree->father->lchild = pMark;
        else
            pTree->father->rchild = pMark;
    }
    else
        ROOT = pMark;

    if (pTree->lchild)
        pTree->lchild->father = pTree;
    pMark->father = pTree->father;
    pTree->father = pMark;
}

Node *getUncle(Node *pNode)
{
    if (pNode && pNode->father)
    {
        if (pNode->father->lchild == pNode)
            return pNode->father->rchild;
        return pNode->father->lchild;
    }
    return NULL;
}

Node *add_Search(Node *pTree, int val)
{
    if (pTree == NULL)
        return NULL;

    while (pTree)
    {
        if (pTree->val > val)
        {
            if (pTree->lchild == NULL)
                return pTree;
            pTree = pTree->lchild;
        }
        else if (pTree->val < val)
        {
            if (pTree->rchild == NULL)
                return pTree;
            pTree = pTree->rchild;
        }
        else
        {
            cout << "数据有误" << endl;
            exit(1);
        }
    }
    return NULL;
}

void add_Node(Node *root, int val)
{
    //找父节点
    Node *pNode = add_Search(root, val); //返回新节点的父亲
    Node *pTemp = getNewNode(val);
    pTemp->father = pNode;
    if (pNode == NULL)
    {
        ROOT = pTemp;
        ROOT->color = BLACK;
        return;
    }
    //插入节点
    if (pNode->val > pTemp->val)
        pNode->lchild = pTemp;
    else
        pNode->rchild = pTemp;

    //一、父亲是黑色
    if (pNode->color == BLACK)
        return;
    //二、父亲是红色
    Node *GrandFather = NULL;
    //爷爷节点一定存在，因为父亲是红色，不可能是根节点
    Node *Uncle = NULL;
    while (pNode->color == RED)
    {
        GrandFather = pNode->father;
        Uncle = getUncle(pNode);
        //二、1叔叔是红色
        if (Uncle != NULL && Uncle->color == RED)
        {
            Uncle->color = BLACK;
            pNode->color = BLACK;
            GrandFather->color = RED;
            //下面两句是看 爷爷节点变红后是否会于它的父亲产生矛盾
            pTemp = GrandFather;
            pNode = pTemp->father;
            if (pNode == NULL) // pTemp为根
            {
                ROOT->color = BLACK;
                break;
            }
        }
        //二、2叔叔是黑色
        else
        {
            if (pNode == GrandFather->lchild)
            {
                if (pTemp == pNode->rchild)
                {
                    pTemp = pNode;
                    left_rotate(pTemp);
                    pNode = pTemp->father;
                }

                if (pTemp == pNode->lchild)
                {
                    pNode->color = BLACK;
                    GrandFather->color = RED;
                    right_rotate(GrandFather);
                    break;
                }
            }
            else if (pNode == GrandFather->rchild)
            {
                if (pTemp == pNode->lchild)
                {
                    pTemp = pNode;
                    right_rotate(pTemp);
                    pNode = pTemp->father;
                }
                if (pTemp == pNode->rchild)
                {
                    pNode->color = BLACK;
                    GrandFather->color = RED;
                    // if(GrandFather->father == NULL) //GF是根节点
                    left_rotate(GrandFather);

                    break;
                }
            }
        }
    }
}

void CreatNode(int *arr, int len)
{
    if (arr == NULL || len <= 0)
        return;
    for (int i = 0; i < len; i++)
    {
        add_Node(ROOT, arr[i]);
    }
    // ROOT->father = NULL;
}

Node *erase_Search(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    while (root)
    {
        if (root->val == val)
            return root;
        if (root->val > val)
            root = root->lchild;
        else if (root->val < val)
            root = root->rchild;
    }
    return NULL;
}

Node *pre_Node(Node *root)
{
    Node *temp = root->rchild;
    while (temp->lchild)
        temp = temp->lchild;
    return temp;
}

void erase_Node(Node *root, int val)
{
    if (root == NULL)
        return;
    //查找
    Node *pNode = erase_Search(root, val); //找到删除的节点
    if (pNode == NULL)
        return;
    if (pNode->lchild && pNode->rchild) //将2个节点转化为1/0个节点的问题
    {
        Node *pTemp = pre_Node(pNode);
        pNode->val = pTemp->val;
        pNode = pTemp;
    }

    //------------------以下的pNode 都是只有一个或0个孩子的节点--------------------------------------
    Node *Father = NULL;

    Father = pNode->father;
    //删除的是根节点
    if (Father == NULL)
    {
        if (pNode->lchild == NULL && pNode->rchild == NULL) //根无孩子
        {
            free(pNode);
            pNode = NULL;
            ROOT = NULL;
            return;
        }
        else //根有一个孩子
        {
            (pNode->lchild != NULL) ? ROOT = pNode->lchild : ROOT = pNode->rchild;
            ROOT->color = BLACK;
            ROOT->father = NULL;
            free(pNode);
            pNode = NULL;
            return;
        }
    }

    // 删除节点是红色红色节点  红叶子节点
    if (pNode->color == RED)
    {
        (pNode == Father->lchild) ? (Father->lchild = NULL) : (Father->rchild = NULL);
        free(pNode);
        pNode = NULL;
        return;
    }

    //删除节点是黑色
    //若有一个孩子 （必定是红孩子）
    if (pNode->lchild || pNode->rchild)
    {
        //将红孩子变黑，接替被删除节点的位子
        Node *pTemp = (pNode->lchild != NULL) ? pNode->lchild : pNode->rchild;
        pTemp->father = Father;
        pTemp->color = BLACK;
        (Father->lchild == pNode) ? (Father->lchild = pTemp) : (Father->rchild = pTemp);
        free(pNode);
        pNode = NULL;
        return;
    }
    else //黑色节点  且无孩子  但一定有兄弟
    {
        Node *brother = (Father->lchild == pNode) ? Father->rchild : Father->lchild;
        //删除
        (Father->lchild == pNode) ? (Father->lchild = NULL) : (Father->rchild = NULL);
        free(pNode);
        pNode = NULL;
        //兄弟为红色
        while (1)
        {
            if (brother->color == RED)
            {
                //父亲变红，兄弟变黑 ，以父亲为节点旋转
                Father->color = RED;
                brother->color = BLACK;
                if (Father->lchild == brother)
                {
                    right_rotate(Father);
                    brother = Father->lchild;
                }
                else
                {
                    left_rotate(Father);
                    brother = Father->rchild;
                }
                continue;
            }

            //兄弟为黑色  看侄子
            else
            {
                //两个侄子全是黑色或不存在
                if ((brother->lchild == NULL || brother->lchild->color == BLACK) &&
                    (brother->rchild == NULL || brother->rchild->color == BLACK))
                {
                    if (Father->color == RED) //父亲为红色
                    {
                        brother->color = RED;
                        Father->color = BLACK;
                        break;
                    }
                    else //父亲为黑色
                    {
                        brother->color = RED;
                        //以父亲为讨论点继续讨论
                        pNode = Father;
                        Father = pNode->father;
                        if (Father == NULL) //根节点
                            break;
                        brother = (Father->lchild == pNode) ? Father->rchild : Father->lchild;
                        continue;
                    }
                }

                //至少有一个侄子是红色的
                //兄弟在左边
                if (Father->lchild == brother)
                {
                    if (brother->rchild && brother->rchild->color == RED && // LR型问题
                        (brother->lchild == NULL || brother->lchild->color == BLACK))
                    {
                        brother->color = RED;
                        brother->rchild->color = BLACK;
                        left_rotate(brother);
                        brother = Father->lchild; //更新brother节点
                    }
                    if (brother->lchild && brother->lchild->color == RED) // LL型问题
                    {
                        Father->rchild = NULL;
                        brother->color = Father->color;
                        Father->color = BLACK;
                        brother->lchild->color = BLACK;
                        right_rotate(Father);
                        return;
                    }
                }
                //兄弟在右边边
                if (Father->rchild == brother)
                {
                    if (brother->lchild && brother->lchild->color == RED && // RL型问题
                        (brother->rchild == NULL || brother->rchild->color == BLACK))
                    {
                        brother->color = RED;
                        brother->lchild->color = BLACK;
                        right_rotate(brother);
                        brother = Father->rchild; //更新brother节点
                    }
                    if (brother->rchild && brother->rchild->color == RED) // RR型问题
                    {
                        Father->lchild = NULL;
                        brother->color = Father->color;
                        Father->color = BLACK;
                        brother->rchild->color = BLACK;
                        left_rotate(Father);
                        return;
                    }
                }
            }
        }
    }
}

void pre_order(Node *root)
{
    if (root == NULL)
        return;
    printf("color: %d    ", root->color);
    printf("val:   %d\n", root->val);
    pre_order(root->lchild);
    pre_order(root->rchild);
    return;
}

int main()
{
    int arr[] = {11, 2, 14, 1, 7, 15, 5, 8};
    //int arr[] = {5, 8};
    int len = sizeof(arr) / sizeof(int);
    CreatNode(arr, len);
    //add_Node(ROOT, 15);
    pre_order(ROOT);
    if (ROOT->father)
    {
        cout << ROOT->val << endl;
        cout << ROOT->father->val << endl;
        printf("%p\n", ROOT);
        printf("%p\n", ROOT->father);
    }

    int a;
    while (cin >> a)
    {
        printf("\n----------------------\n");
        erase_Node(ROOT, a);
        pre_order(ROOT);
        printf("\n----------------------\n");
    }

    /*
        printf("\n----------------------\n");
        erase_Node(ROOT, 11);
        pre_order(ROOT);
        printf("\n----------------------\n");
        erase_Node(ROOT, 14);
        pre_order(ROOT);

      */

    system("pause");
    return 0;
}