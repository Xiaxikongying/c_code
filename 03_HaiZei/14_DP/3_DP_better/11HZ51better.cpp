#include <iostream>
#include <stack>
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
int dp[1005] = {0};
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
        stack<int> s;
        f[i][m + 1] = -1;
        s.push(m + 1); //在最右边放入一个极小值，使得每个值都可以找到right
        for (int j = m; j > 0; j--)
        {
            while (f[i][s.top()] > f[i][j]) //维护一个较小的right序列
                s.pop();
            //此时栈顶一定是一个比f[i][j]小的数（即为我们此前求的k
            dp[j] = f[i][j] * (s.top() - j) + dp[s.top()];
            ans += dp[j];
            s.push(j);
        }
    }

    cout << ans % 100007 << endl;
    system("pause");
    return 0;
}
