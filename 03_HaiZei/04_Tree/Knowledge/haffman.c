#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getdata()
{
    printf("26\n");
    srand(time(0));
    for (int i = 0; i < 26; i++)
    {
        printf("%c %d\n", 'a' + i, rand() % 10000);
    }
}

typedef struct Node
{
    struct Node *lchild, *rchild;
    char ch;
    int freq;
} Node;

Node *getNewNode(int freq, char ch)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->rchild = p->lchild = NULL;
    return p;
}

void clear(Node *root)
{
    if (root == NULL)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
void swap_node(Node **node_arr, int min, int j)
{
    Node *temp = node_arr[min];
    node_arr[min] = node_arr[j];
    node_arr[j] = temp;
}

int find_min_node(Node **node_arr, int n)
{
    int min = 0;
    for (int j = 1; j <= n; j++)
    {
        if (node_arr[min]->freq > node_arr[j]->freq)
            min = j;
    }
    return min;
}

Node *buildHaffmanTree(Node **node_arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int min1 = find_min_node(node_arr, n - i);
        //找到最小值的下标
        swap_node(node_arr, min1, n - i);
        //把最小值与尾部交换

        int min2 = find_min_node(node_arr, n - i - 1);
        swap_node(node_arr, min2, n - i - 1);
        //找到第二小的数
        int f = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;
        Node *node = getNewNode(f, 0);
        node->lchild = node_arr[n - i - 1];
        node->rchild = node_arr[n - i];

        node_arr[n - i - 1] = node;
    }
    return node_arr[0];
}

void extractHaffmanCode(Node *root, char buff[], int k)
{
    buff[k] = 0;
    if (root->rchild == NULL && root->lchild == NULL)
    {
        printf("%c :%s\n", root->ch, buff);
        return;
    }

    buff[k] = '0';
    extractHaffmanCode(root->lchild, buff, k + 1);

    buff[k] = '1';
    extractHaffmanCode(root->rchild, buff, k + 1);
    return;
}

int main()
{

    int n;
    scanf("%d", &n);
    char s[10];
    int freq;

    Node **node_arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", s, &freq);
        node_arr[i] = getNewNode(freq, s[0]);
    }
    printf("---------------------------------------------------\n\n");
    Node *root = buildHaffmanTree(node_arr, n);
    char buff[1000];
    extractHaffmanCode(root, buff, 0);
    clear(root);
    system("pause");
    return 0;
}