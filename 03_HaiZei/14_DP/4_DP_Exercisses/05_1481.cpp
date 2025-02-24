#include <iostream>
using namespace std;

int dp[2005];
string val[2005];
/*
P1481 魔族密码
5
i
int
integer
intern
internet
*/
int main()
{
    int n, ans = 0, flag = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        flag = 1;
        cin >> val[i];
        dp[i] = 1;
        for (int j = i - 1; j >= 1 && flag; j--)
        {
            if (val[i].find(val[j]) == 0)
            {
                dp[i] = max(dp[i], dp[j] + 1);
                flag = 0;
            }
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}


//用find代替
bool is_pre(int i, int j) // j是否是i的前缀
{
    if (val[i].size() > val[j].size())
    {
        for (int a = 0; a < val[j].size(); a++)
        {
            if (val[i][a] != val[j][a])
                return false;
        }
        return true;
    }
    return false;
}
