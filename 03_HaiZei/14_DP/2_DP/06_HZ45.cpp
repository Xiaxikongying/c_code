#include <iostream>
#include <cstring>
using namespace std;

/*
HZOJ 45 最长公共子序列
sehuaizexi
yhaizeyiux
6
*/

int dp[1005][1005] = {0};
// dp[i][j]  表示s1的前i位  与 s2的前j位 的最长公共子序列长度
char s1[1005];
char s2[1005];

int main()
{
    cin >> (s1 + 1) >> (s2 + 1); // 0位置空出来
    int n = strlen(s1 + 1);
    int m = strlen(s2 + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    cout << dp[n][m] << endl;
    system("pause");
    return 0;
}
