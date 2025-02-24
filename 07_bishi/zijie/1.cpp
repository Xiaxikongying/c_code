#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
int degree[MAXN]; // 记录每个节点的度数

int main()
{
    int n;
    cin >> n;

    // 输入n-1条边
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // 计算可添加的边数
    long long res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] >= 2)
        {
            res += 1LL * degree[i] * (degree[i] - 1) / 2;
        }
    }

    cout << res << endl;
    system("pause");
    return 0;
}

/*
小红有一棵n个点、n-1条边的树。如果树上存在一个点w，使得原始的树上存在边（u,w)和(w,v)，那么我
们可以添加一条边(u,v)。小红想知道她最多可以添加多少条边。
树是指这样的一张图，其上的任意两个点都连通，且不存在环。

输入描述
第一行输入-个整数n(2≤n≤2*10^5）代表树上的点的个数。
此后n-1行，第i行输入两个整数ui和vi(1≤ui,vi≤n；ui≠vi）表示树上第i条边连接节点ui和vi。保证树联通，没有重边。

示例1
输入:
5
1 2
1 3
2 4
2 5
输出:4
说明:可以添加的边为(1,4)，(1,5)，(2,3)，(4,5)。
用C++写出上述程序

*/