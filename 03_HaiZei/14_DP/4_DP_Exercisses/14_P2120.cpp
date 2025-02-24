#include <iostream>
using namespace std;

int dp[10005]; // dp[i]表示 前i个工厂的最低费用
int S[10005];
int T[10005];
int q[10005];

#define f(n) (dp[n] + t[n])
double slope(int i, int j)
{
    return 1.0 * (f(i) - f(j)) / (s[i] - s[j]);
}

/*
工厂建设
3
0 5 10
5 3 100
9 6 10
*/
int main()
{
    int n, dis, num, w, head, tail;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dis >> num >> w;
        S[i] = num + S[i - 1];       // 产品数量 前缀和
        T[i] = num * dis + T[i - 1]; // 产品数量 * 距离前缀和
        
        dp[i] = dp[i - 1] + w;           // 表示在i处建厂
        for (int j = i - 2; j >= 0; j--) // 枚举上一个厂的位置在j  [j+1~i]的全部货物都要运送到i
        {
            int t = dis * (S[i] - S[j]) - (T[i] - T[j]);
            dp[i] = min(dp[i], dp[j] + w + t);
        }
    }
    cout << dp[n] << endl;
    system("pause");
    return 0;
}
