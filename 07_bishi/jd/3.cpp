#include <iostream>
#include <vector>
using namespace std;

const int MOD = 20220201;

int main()
{
    int n, m, a;
    cin >> n >> m >> a;

    vector<vector<int>> dp(n + 1, vector<int>(a + 1, 0));
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dp[1][0] = 1; // 到达城市1，花费0有1种方法

    for (int i = 0; i <= a; ++i) // 遍历每种花费
    {
        for (int u = 1; u <= n; ++u) // 遍历每个城市
        {
            if (dp[u][i] > 0)
            {
                int v, w;
                for (auto &edge : adj[u]) // 遍历城市u的每条路
                {
                    v = edge.first;  // 目的地
                    w = edge.second; // 花费
                    if (i + w <= a)
                        dp[v][i + w] += dp[u][i];
                }
            }
        }
    }

    int res = dp[n][a];
    if (res >= MOD)
    {
        cout << "All roads lead to Home!" << endl;
        cout << res % MOD << endl;
    }
    else
        cout << res << endl;
    system("pause");
    return 0;
}

/*
牛牛也是要回家过年的呢。
牛牛所在的国家有n座城市，m条有向道路，第i条道路由城市ui通往城市，通行费为wi。
作为一头豪气的牛，希望他回家的花费是一个特殊的数字（例如666元）。具体的说，牛牛希望从城市1移动到城市n，并恰好花费a元。
请你告诉牛牛，他有多少种回家的方案？
输入描述
第一行三个整数n,m,a(1≤n≤100,1 ≤m≤1000,1 ≤a≤ 1000)，含义如题面所示。
接下来m行，第i行三个整数ui，vi，wi（1≤ui，vi≤n,1≤wi≤a)，描述了-条道路。
输出描述
如果牛牛回家的方案数大于等于20220201种，请你在第一行输出All roads lead to Home！，然后在第二行输出回家的方案数对20220201取模的结果。
否则只需要输出一行一个整数，表示牛牛回家的方案数。
示例1
输入
3 6 2
1 2 1
1 2 1
1 2 1
2 3 1
2 3 1
2 3 1
输出
9
说明：从城市一到城市二有3种不同的走法，从城市二到城市三也有3种不同的走法，根据乘法原理我们可以知道，一共
有3×3=9种不同的回家方法。
*/