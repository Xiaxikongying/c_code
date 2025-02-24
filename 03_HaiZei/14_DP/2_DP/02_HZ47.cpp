#include <iostream>
#include <algorithm>
using namespace std;
/*
0/1背包问题
15 4
4 10
3 7
12 12
9 8

19
*/
int dp[10005] = {0};
// dp[j]表示承重为j时的最大价值为
int main()
{
    int n, V; // n件商品  总承重为V
    cin >> V >> n;

    for (int i = 1, v, w; i <= n; i++) //每一个物品都循环一次
    {
        cin >> v >> w;
        for (int j = V; j >= v; j--)
        {
            /*
            为什么要倒者扫描？
            必须确保dpp[j]更新前，dp[j-v]没有被跟新

            例如 当v = 3 ，w = 7时
            此前没有小于3kg的物品  所以dp[3] =7
            但是当j = 6时，max(dp[6], (dp[3] + w));---->max(10,(7+7))
            这就是因为正序扫描时，改变的前面的值
            即用了两次3/7的物品 不符合题意
            */
            dp[j] = max(dp[j], (dp[j - v] + w));
        }
    }

    cout << dp[V] << endl;
    system("pause");
    return 0;
}

/*
int v[105], w[105];
int dp[105][10005] = {0};

int main()
{
    int V, n;
    scanf("%d%d", &V, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", v + i, w + i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j < v[i])
                continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            //在这里 i值看起来好像没有什么用，毕竟在执行这条语句之前 dp[i][j]与dp[i-1][j]的值是一样的
            //其他位置的值也是一样
            //所以做成一维数组也是可以的
        }
    }
    printf("%d\n", dp[n][V]);
    return 0;
}

*/
