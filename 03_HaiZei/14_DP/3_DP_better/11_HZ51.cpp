#include <iostream>
using namespace std;
/*
HZ51 矩形个数
6 6
0 1 1 1 1 1
1 1 0 1 1 1
1 1 1 1 1 1
1 1 1 0 1 1
1 1 1 1 0 1
1 0 1 1 1 1
152
*/
int dp[1005][1005] = {0};

int f[1005][1005] = {0};
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> f[i][j];
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            if (f[i][j] == 0)
                continue;
            if (f[i][j] == 1)
                f[i][j] += f[i + 1][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j > 0; j--)
        {
            int k = j;
            while (f[i][j] <= f[i][k] && k <= m)
                k += 1;
            dp[i][j] = f[i][j] * (k - j) + dp[i][k];
            ans += dp[i][j];
        }
    }

    cout << ans % 100007 << endl;
    system("pause");
    return 0;
}

