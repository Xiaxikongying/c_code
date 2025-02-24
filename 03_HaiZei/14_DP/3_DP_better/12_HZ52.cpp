#include <iostream>
using namespace std;

long long dp[1000005] = {0};
long long sum[1000005] = {0};
long long q[1000005] = {0};
int head, tail, n, m, a;
/*
6 40
3 3 6 5 1 2
256
*/
#define POW(n) ((n) * (n))
#define f(n) (dp[n] + POW(sum[n]))

double slope(int i, int j)
{
    return 1.0 * (f(j) - f(i)) / (sum[j] - sum[i]);
}

int main()
{
    cin >> n >> m;
    head = tail = 0;
    q[tail++] = 0; //在开头加上0，添加的不分组的情况
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum[i] = sum[i - 1] + a;

        //看头的斜率  若头部斜率 满足x<2sum[i] 说明head+1优于head   则popfront
        while (tail - head >= 2 && slope(q[head], q[head + 1]) < 2 * sum[i])
            head += 1;
        //将最优的方案写入dp
        dp[i] = dp[q[head]] + POW((sum[i] - sum[q[head]])) + m;

        //判断尾部斜率
        while (tail - head >= 2 && slope(q[tail - 2], q[tail - 1]) > slope(q[tail - 1], i))
            tail -= 1;
        q[tail++] = i;
    }
    cout << dp[n] << endl;
    system("pause");
    return 0;
}
