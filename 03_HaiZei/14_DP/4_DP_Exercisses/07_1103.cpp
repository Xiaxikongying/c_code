#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[105][105]; // dp[i][j] 表示前i本书，选取j本的不整齐度(必须选择第i本书)
struct Data
{
    int h, w;
};
Data book[105];
bool cmp(Data &b1, Data &b2)
{
    return b1.h < b2.h;
}

int main()
{
    int n, K;
    cin >> n >> K;
    K = n - K; // 将去除k本  转换  为选取n-k本书
    for (int i = 1; i <= n; i++)
        cin >> book[i].h >> book[i].w;
    sort(book + 1, book + n + 1, cmp);
    memset(dp, 0x3f, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = 0;
        for (int k = 2; k <= i && k <= K; k++) // 第k本书选择 i
        {
            for (int j = k - 1; j < i; j++) // k-1本 选择哪本书？
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + abs(book[i].w - book[j].w));
        }
    }
    int ans = 0x7fffffff;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][K]);
    cout << ans << endl;
    system("pause");
    return 0;
}
/*
4 2
1 2
2 4
3 1
5 3
*/