#include <iostream>
#include <algorithm>
using namespace std;

//完全背包 每个物品都是无限个数的
/*
5 20
2 3
3 4
10 9
5 2
11 11

30*/
int dp[10005] = {0};
// dp[j]表示承重为j时的最大价值为
int main()
{
    int n, V; // n件商品  总承重为V
    cin  >> n>>V;

    for (int i = 1, v, w; i <= n; i++) //每一个物品都循环一次
    {
        cin >> v >> w;
        for (int j = v; j <= V; j++)
        {
            dp[j] = max(dp[j], (dp[j - v] + w));
        }
    }

    cout << dp[V] << endl;
    system("pause");
    return 0;
}
