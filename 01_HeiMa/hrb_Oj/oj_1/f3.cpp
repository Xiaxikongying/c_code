#include <iostream>
using namespace std;

const int MAXN = 1024 + 5;

int n;
int tree[MAXN];

void inorder(int root)
{
    if (root > n)
        return;
    inorder(2 * root);         // 左子树
    cout << tree[root] << " ";  // 中节点
    inorder(2 * root + 1);     // 右子树
}

int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            tree[i] = i;
        }
        inorder(1); // 从根节点开始遍历
        cout << endl;
    }
    return 0;
}
