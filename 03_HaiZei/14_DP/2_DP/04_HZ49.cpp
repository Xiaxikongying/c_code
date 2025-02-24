#include <iostream>
#include <algorithm>
using namespace std;

//多重背包 每个物品个数都是有限制的
/*
15 4
4 10 5
3 7 4
12 12 2
9 8 7
输入的分别为 重量  价值  数量
37*/
int dp[10005] = {0};
// dp[j]表示承重为j时的最大价值为


//最简单的办法就是当成普通的0/1背包，将复数个当成多个不同的物体计算
//缺点是数据过大时会超时
int main()
{
    int n, V; // n件商品  总承重为V
    cin >> V >> n;

    for (int i = 1, v, w, s; i <= n; i++) //每一个物品都循环一次
    {
        cin >> v >> w >> s;
        while (s != 0)
        {
            for (int j = V; j >= v; j--)
                dp[j] = max(dp[j], (dp[j - v] + w));
            s--;
        }
    }

    cout << dp[V] << endl;
    system("pause");
    return 0;
}
