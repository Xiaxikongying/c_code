#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
/*
多人背包
2 10 5
3 12
7 20
2 4
5 6
1 1
->57
*/
int dp[5005][55]; // dp[i][0] = k 表示dp[i]中存储了前k个最优解--->dp[i][1~k]
int temp[55];     // 用于归并两个数组临时数组
vector<int> res;
int main()
{
    int k, V, n;
    cin >> k >> V >> n;

    dp[0][0] = 1; // dp[0]只有一个解
    dp[0][1] = 0; // 这个解为0
    for (int i = 1, v, w; i <= n; i++)
    {
        cin >> v >> w;
        for (int j = V; j >= v; j--)
        {
            // dp[j]的值只由  先前的dp[j]与dp[j-v] 决定
            int n1 = dp[j][0];
            int n2 = dp[j - v][0];       // 得到两者解的数量
            int p1 = 1, p2 = 1, t = 1;   // 分别是dp[j]  dp[j-v]  temp的指针
            while (p1 <= n1 || p2 <= n2) // 还有值可以导入
            {
                if (p2 > n2 || (p1 <= n1 && dp[j][p1] >= dp[j - v][p2] + w)) // 导入dp[j]的数据
                {
                    temp[t++] = dp[j][p1++];
                }
                else // 导入dp[j-v]的数据
                {
                    temp[t++] = dp[j - v][p2++] + w;
                }
                if (t > k) // 已经合并了足够多的解了
                    break;
            }
            // 将temp中是数据拷贝到dp[j]中
            temp[0] = t - 1;
            memcpy(dp[j], temp, sizeof(int) * t);
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
        ans += dp[V][i];
    cout << ans << endl;
    system("pause");
    return 0;
}
