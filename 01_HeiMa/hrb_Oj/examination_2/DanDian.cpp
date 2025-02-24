#include <iostream>
using namespace std;

typedef struct Node
{
    char ch;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char ch)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->lchild = p->rchild = NULL;
    return p;
}
/*
void clear(Node *root)
{
    if (root = NULL)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
*/
Node *getTree(string s, int i)
{
    Node *root = getNewNode(s[i]);

    if (2 * i + 1 < s.size() && s[2 * i + 1] != '#')
        root->lchild = getTree(s, 2 * i + 1);

    if (2 * i + 2 < s.size() && s[2 * i + 2] != '#')
        root->rchild = getTree(s, 2 * i + 2);

    return root;
}

/*
int n = 0;
int dan(Node *root)
{
     if (root == NULL)
        return 0;
    if ((root->lchild == NULL && root->rchild != NULL) ||
        (root->lchild != NULL && root->rchild == NULL))
        n++;
    dan(root->lchild);
    dan(root->rchild);
    return n;
}
*/

int dan(Node *root)
{
    if (root == NULL)
        return 0;
    if ((root->lchild == NULL && root->rchild != NULL) ||
        (root->lchild != NULL && root->rchild == NULL))
        return 1 + dan(root->lchild) + dan(root->rchild);
    else
        return dan(root->lchild) + dan(root->rchild);
}

int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        Node *root = getTree(s, 0);
        cout << dan(root) << endl;
        // n=0;
        //  clear(root);
    }
    system("pause");
    return 0;
}