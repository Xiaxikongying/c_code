#include <iostream>
#include <cstring>
using namespace std;

typedef struct Node
{
    int count;
    struct Node *Next[26];
    string val;
} Node;

Node *getNewNode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    memset(p->Next, 0, sizeof(Node));
    p->count = 0;
    p->val = " ";
    return p;
}

Node *ROOT = getNewNode();

void insert_Trie(Node *root, string val)
{
    Node *pNode = root;
    int len = val.length();
    for (int i = 0; i < len; i++)
    {
        int index = val[i] - 97;
        if (!pNode->Next[index])
            pNode->Next[index] = getNewNode();//若存在，则跳转下一节点；若不存在，则先创建在进入Next
        pNode = pNode->Next[index];
        //注意无论存不存在都需要将pNode送至下一节点，千万不可以用else
    }
    pNode->count++;
    pNode->val = val;
}

int search_Trie(Node *root, string val)
{
    Node *pNode = root;
    int len = val.length();
    for (int i = 0; i < len; i++)
    {
        if (pNode->Next[val[i] - 97])
            pNode = pNode->Next[val[i] - 97];
        else
            return 0;
    }
    return pNode->count;
}

void output(Node *root)
{
    if (root == NULL)
        return;
    if (root->count != 0)
        cout << root->val << endl;
    for (int i = 0; i < 26; i++)
        output(root->Next[i]);
}

int main()
{
    string s;
    int a = 5;
    while (a--)
    {
        cin >> s;
        insert_Trie(ROOT, s);
    }
    output(ROOT);
    system("pause");
    return 0;
}
/*
  cin >> s;
        if (search_Trie(ROOT, s) > 0)
            cout << "查找成功" << endl;
        else
            cout << "查找失败" << endl;
*/