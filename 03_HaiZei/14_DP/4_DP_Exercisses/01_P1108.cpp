#include <iostream>
using namespace std;
#define MAX_N 5000
#define INF 0x7fffffff
/*
低价购买
12
68 69 54 64 68 64 70 67 78 62 98 87
*/
int dp[MAX_N + 5] = {0};
int len[MAX_N + 5] = {0};
int val[MAX_N + 5] = {0};
int f[MAX_N + 5] = {0}; //表示方法总数

int find(int n, int val) //找到一个刚好小于等于val的位置
{
    for (int i = 0; i <= n; i++)
    {
        if (len[i] <= val)
            return i - 1;
    }
    return n;
}

int main()
{
    int n, len_max = 0;
    cin >> n;
    val[0] = len[0] = INF;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        dp[i] = find(len_max, val[i]) + 1;
        len[dp[i]] = val[i];
        if (dp[i] > len_max)
            len_max += 1;

        for (int j = 0; j < i; j++) //求f[i]
        {
            if (val[i] > val[j])
                continue;
            else if (val[i] < val[j] && dp[i] == dp[j] + 1)
                f[i] += f[j];
            else if (val[i] == val[j] && dp[i] == dp[j]) //因为相同的数字不算路径，所以用后面的数字作为路径很为合适
                f[j] = 0;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == len_max)
            ans += f[i];
    }
    cout << len_max << " " << ans << endl;
    system("pause");
    return 0;
}
