#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_M 3 // 5阶B树
#define MAX_OP 15
#define LAST_KEY(root) (root->key[root->n - 1])
#define LAST_CHILD(root) (root->next[root->n])
#define swap(a, b)           \
    {                        \
        __typeof(a) __c = a; \
        a = b, b = __c;      \
    }

typedef struct Node
{
    int n;              //存储关键字的数量
    int key[MAX_M + 1]; //关键字的值
    struct Node *next[MAX_M + 1];
} Node;

Node *getNewNode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->n = 0;
    memset(p->next, 0, sizeof(Node *) * (MAX_M + 1));
    return p;
}

Node *insert_maintain(Node *root, Node *child, int pos)
{
    if (child->n < MAX_M) //节点没有超出上限
        return root;

    //若超出上限 则提取出中间的值
    int spos = MAX_M / 2;
    Node *node1 = getNewNode(); // spos前面的  key[0,spos-1]  next[0,spos]
    Node *node2 = getNewNode(); // spos后面的  key[spos+1,n-1]  next[spos+1,n]
    node1->n = spos;
    node2->n = MAX_M - 1 - spos;
    for (int i = 0; i < spos; i++)
    {
        node1->key[i] = child->key[i];
        node1->next[i] = child->next[i];
    }
    node1->next[spos] = child->next[spos];

    for (int i = 0; i < node2->n; i++)
    {
        node2->key[i] = child->key[spos + i + 1];
        node2->next[i] = child->next[spos + i + 1];
    }
    node2->next[node2->n] = child->next[child->n];

    for (int i = root->n; i >= pos; i--)
    {
        root->key[i + 1] = root->key[i];
        root->next[i + 1] = root->next[i];
    }
    root->key[pos] = child->key[spos];
    root->next[pos] = node1;
    root->next[pos + 1] = node2;
    root->n++;
    free(child);
    return root;
}

Node *insert_key(Node *root, int key)
{
    if (root == NULL)
    {
        root = getNewNode();
        root->key[root->n] = key;
        root->n++;
        return root;
    }
    int pos = 0;
    while (pos < root->n && root->key[pos] < key)
        pos++; //使pos指向一个刚好大于(等于)key的位置

    if (root->key[pos] == key)
        return root; //值相同，不插入

    for (int i = root->n - 1; i >= pos; i--)
    {
        root->key[i + 1] = root->key[i];
        // pos后的数据全向后移一位，为插入的值腾出位置
    }
    root->key[pos] = key;
    root->n++;
    return root;
}

Node *__insert(Node *root, int key)
{
    if (root == NULL || root->next[0] == NULL)
        return insert_key(root, key);

    int pos = 0;
    while (pos < root->n && root->key[pos] < key)
        pos++; //指向一个刚好大于(等于)key的值
    if (pos < root->n && root->key[pos] == key)
        return root; //值相等 直接返回

    __insert(root->next[pos], key);
    return insert_maintain(root, root->next[pos], pos);
}

Node *insert(Node *root, int key)
{
    root = __insert(root, key);
    if (root->n == MAX_M)
    {
        Node *p = getNewNode();
        p->next[0] = root;
        root = insert_maintain(p, root, 0);
    }
    return root;
}

void left_rotate(Node *root, int pos)
{
    LAST_KEY(root->next[pos]) = root->key[pos];
    root->next[pos]->n++;
    root->key[pos] = root->next[pos + 1]->key[0];
    LAST_CHILD(root->next[pos]) = root->next[pos + 1]->next[0];
    for (int i = 0; i < root->next[pos]->n; i++)
    {
        root->next[pos]->key[i] = root->next[pos]->key[i + 1];
        root->next[pos]->next[i] = root->next[pos]->next[i + 1];
    }
    LAST_CHILD(root->next[pos + 1]) = NULL;
    root->next[pos]->n--;
    return;
}

void right_rotate(Node *root, int pos)
{
    //右子树全部向后移动一位  为父节点的到来腾出位子
    for (int i = root->next[pos + 1]->n + 1; i > 0; i--)
    {
        root->next[pos + 1]->key[i] = root->next[pos + 1]->key[i - 1];
        root->next[pos + 1]->next[i] = root->next[pos + 1]->next[i - 1];
    }
    root->next[pos + 1]->key[0] = root->key[pos];               //根节点关键字移动到右边
    root->key[pos] = LAST_KEY(root->next[pos]);                      //左子树关键字移动到父节点
    root->next[pos + 1]->next[0] = LAST_CHILD(root->next[pos]); //左子树的next移动到右边
    LAST_CHILD(root->next[pos]) = NULL;
    root->next[pos]->n--;
    root->next[pos + 1]->n++;
}

void merge_node(Node *root, int pos)
{
    Node *node = getNewNode();
    for (int i = 0; i <= root->next[pos]->n; i++)
    {
        node->key[i] = root->next[pos]->key[i];
        node->next[i] = root->next[pos]->next[i];
    }
    node->key[node->n] = root->key[pos];
    node->n++;
    for (int i = 0; i <= root->next[pos + 1]->n; i++)
    {
        node->key[i + node->n] = root->next[pos + 1]->key[i];
        node->next[i + node->n] = root->next[pos + 1]->next[i];
    }
    node->n += root->next[pos + 1]->n;
    free(root->next[pos]);
    free(root->next[pos+1]);
    for (int i = pos + 1; i <= root->n;i++)
    {
        root->key[i - 1] = root->key[i];
        root->next[i - 1] = root->next[i];
    }
        root->next[pos] = node;
        root->n--;
        return;
}

Node *erase_maintain(Node *root, int pos)
{
    int lower_bound = (MAX_M + 1) / 2 - 1; //每个节点最小节点个数
    if (root->next[pos]->n >= lower_bound)
        return root;

    //当前节点个数不够，向兄弟借一个节点
    if (pos > 0 && root->next[pos - 1]->n > lower_bound)
        right_rotate(root, pos - 1);
    else if (pos > 0 && root->next[pos + 1]->n > lower_bound)
        left_rotate(root, pos);

    //若前后节点都不够  就合并
    else
    {
        if (pos > 0)
            merge_node(root, pos - 1); //(i,j) 表示合并j和j+1
        else
            merge_node(root, pos);
    }
    return root;
}

void erase_pos(Node *root, int pos) //删除终端节点
{
    for (int i = pos + 1; i < root->n; i++)
        root->key[i - 1] = root->key[i];
    root->n--;
    return;
}

Node *__erase(Node *root, int key)
{
    if (root == NULL)
        return root;

    int pos = 0;
    while (pos < root->n && root->key[pos] < key)
        pos++;
    if (root->next[0] == NULL) //终端节点的删除
    {
        if (root->key[pos] == key)
            erase_pos(root, pos);
        return root;
    }
    else //非终端节点
    {
        if (pos < root->n && root->key[pos] == key) //找到删除节点
        {
            //找前驱节点
            Node *temp = root->next[pos];
            while (temp->next[temp->n])
                temp = temp->next[temp->n];
            //删除 覆盖给root的值
            swap(root->key[pos], temp->key[temp->n - 1]);
            int val = temp->key[temp->n - 1];
            root->next[pos] = __erase(root->next[pos], val);
        }
        //没有找到当前待删除节点 到下一层找
        root->next[pos] = __erase(root->next[pos], key);
        return erase_maintain(root, pos);
    }
}

Node *erase(Node *root, int key)
{
    root = __erase(root, key);
    if (root->n == 0)
    {
        Node *temp = root->next[0];
        free(root);
        root = temp;
    }
    return root;
}

void clear(Node *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->n; i++)
    {
        clear(root->next[i]);
    }
    free(root);
    return;
}

void printf_node(Node *root)
{
    printf("%d : ", root->n);
    for (int i = 0; i < root->n; i++)
    {
        printf("%4d", root->key[i]);
    }
    printf("|");
    if (root->next[0] == NULL)
    {
        printf("\n");
        return;
    }
    for (int i = 0; i < root->n; i++)
    {
        printf("%4d", root->next[i]->key[0]);
    }
    printf("\n");
    return;
}

void output(Node *root)
{
    if (root == NULL)
        return;
    printf_node(root);
    for (int i = 0; i < root->n; i++)
    {
        output(root->next[i]);
    }
}

int main()
{

    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++)
    {
        int val = rand() % 100;
        printf("inser %d to BTree\n", val);
        root = insert(root, val);
        output(root);
        printf("\n");
    }

    int x;
    while(~scanf("%d",&x))
    {
        printf("erase %d from BTree \n", x);
        root = erase(root, x);
        output(root);
    }

    system("pause");
    return 0;
}