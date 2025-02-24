
/*
杂务
垃圾题目   描述一大堆，简单的很。
专门恶心人用的
7
1 5 0
2 2 1 0
3 3 2 0
4 6 1 0
5 1 2 4 0
6 8 2 4 0
7 4 3 5 6 0
*/
#include <iostream>
using namespace std;
int dp[10005] = {0};
int main()
{
    int n, a, t, b, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> t; //序号 时间
        dp[i] = t;
        while (cin >> b) //前置工作
        {
            if (b == 0)
                break;
            dp[i] = max(dp[i], dp[b] + t);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
