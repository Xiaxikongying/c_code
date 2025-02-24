#include <iostream>
using namespace std;

int dp[1505][1505];
int arr[1505][1505];
/*
3 3
0 1 0
1 0 0
1 1 1
*/
int myMin(int a, int b, int c)
{
    if (a > b)
        return b > c ? c : b;
    return a > c ? c : a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = 1;
            if (i == 1 | j == 1)
                continue;
            if (arr[i][j - 1] == arr[i - 1][j] && arr[i][j] != arr[i][j - 1])
                dp[i][j] = myMin(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
