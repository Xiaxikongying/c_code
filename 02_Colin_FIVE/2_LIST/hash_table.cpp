#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

typedef struct Node
{
    struct Node *next;
    int key;
} Node;

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    return p;
}

typedef struct HashTable
{
    Node **data;//存放node指针的地址的值
    int size;
} HashTable;

HashTable *getNewHash(int n)
{
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Node **)malloc(sizeof(Node*) * n);
    memset(h->data, 0, sizeof(Node *) * n);
    h->size = n;
    return h;
}

void insert(HashTable *h, int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int ind = arr[i] % h->size;
        Node *p = getNewNode(arr[i]);
        p->next = h->data[ind];
        h->data[ind] = p;
    }
}

void output(HashTable *h)
{
    for (int i = 0; i < h->size; i++)
    {
        {
            cout << i << ":  ";
            Node *p = h->data[i];
            while (p)
            {
                cout << p->key << " ";
                p = p->next;
            }
            printf("\n");
        }
    }
    return;
}

int find(HashTable *h, int target)
{
    int ind = target % h->size;
    Node *p = h->data[ind];
    int cnt = 0;
    while (p)
    {
        cnt += 1;
        if (p->key == target)
            return cnt;
        p = p->next;
    }
    return -1;
}

int main()
{
    int arr[50];
    int a;
    srand(time(0));
    for (int i = 0; i < 50; i++)
    {
        a = rand() % 100; //0-99
        arr[i] = a;
    }

    HashTable *h = getNewHash(13);
    insert(h, arr, 50);
    output(h);

    cout << endl;
    cout << "请输入你要寻找的值：";
    int target;
    cin >> target;
    int ind = target % h->size;
    int flag = find(h, target);
    if(flag!=-1)
    {
        cout << "成功寻找到target" << endl;
        cout << "target 在第 " << ind << " 组，第 " << flag << " 个" << endl;
    }
    else
    {
        cout << "查找失败, 无target值" << endl;
    }

    system("pause");
    return 0;
}