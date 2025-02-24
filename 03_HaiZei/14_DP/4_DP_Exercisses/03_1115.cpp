#include <iostream>
using namespace std;

/*
P1115 最大子段和
7
2 -4 3 -1 2 -4 3

4
*/
int dp[200005] = {0};
int main()
{
    int n, val;
    cin >> n;
    int ans = -0x80000000;
    int head = 0;
    int th = 0;
    int tail = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        dp[i] = max(val, val + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
