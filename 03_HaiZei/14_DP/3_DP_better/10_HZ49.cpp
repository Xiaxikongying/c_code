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
int dp[100005] = {0};
// dp[j]表示承重为j时的最大价值为
int main()
{
    int n, V; // n件商品  总承重为V
    scanf("%d%d", &V, &n);

    for (int i = 1, v, w, s; i <= n; i++) //每一个物品都循环一次
    {
        scanf("%d%d%d", &v, &w, &s);
        //将s件相同的物品分成若干堆物品 如14个1 ---->1 2  4 7
        for (int k = 1; s; s -= k, k *= 2)
        {
            k = min(s, k);
            //此时的物品是 k个i组成的--->v = k*v   w = k*w
            for (int j = V; j >= v * k; j--)
                dp[j] = max(dp[j], dp[j - v * k] + w * k);
        }
    }

    cout << dp[V] << endl;
    system("pause");
    return 0;
}
//----------------------------------------------------------------
//分堆法
int dp[100005] = {0};
int main()
{
    int n, V; // n件商品  总承重为V
    cin >> V >> n;
    for (int i = 1, v, w, s; i <= n; i++) //每一个物品都循环一次
    {
        cin >> v >> w >> s;
        for (int k = 0; s > 0; s -= k, k *= 2)
        {
            k = min(s, k);
            for (int j = v * k; j <= V; j++)
                dp[j] = max(dp[j], (dp[j - v * k] + w * k));
        }
    }
    cout << dp[V] << endl;
}

//-----------------------------------------------------------------------------------------------
//单调队列法
#include <iostream>
#include <deque>
using namespace std;

int dp[2][100005] = {0};
int main()
{
    int Vmax, n;
    cin >> Vmax >> n;
    int v, w, s; //重量  价格   数量
    int a = 1, b = 0;
    for (int i = 1; i <= n; i++) //遍历每种物品
    {
        cin >> v >> w >> s;
        swap(a, b);
        for (int r = 0; r < v; r++) //遍历第i个物品的每种余数
        {
            deque<int> q;
            for (int j = r; j <= Vmax; j += v) //从余数开始遍历
            {
                dp[a][j] -= j / v * w;
                while (!q.empty() && dp[a][j] > dp[a][q.back()])
                    q.pop_back();
                q.push_back(j);

                if ((j - q.front()) / v > s)
                    q.pop_front();

                dp[b][j] = dp[a][q.front()] + j / v * w;
            }
        }
    }

    cout << dp[b][Vmax] << endl;
    system("pause");
    return 0;
}
