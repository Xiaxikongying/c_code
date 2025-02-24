#include <iostream>
using namespace std;
#define ll long long

ll dp[1000005]; // dp[i]表示 前i个工厂的最低费用
ll S[1000005];  // 产品数量 前缀和
ll T[1000005];  // 产品数量 * 距离前缀和
ll f[1000005];  // dp[i] * T
ll q[1000005];

bool better(ll j, ll k, ll dis) // j是否优于k  (head+1  head)
{
    if (f[j] - f[k] < dis * (S[j] - S[k]))
        return true;
    return false;
}

bool slope(ll i, ll j, ll k) // 判断末尾三个点
{
    ll A = f[i] - f[j]; // AC是新插入节点  与  最后一点的斜率
    ll B = f[j] - f[k]; // BD是最后两点的斜率
    ll C = S[i] - S[j];
    ll D = S[j] - S[k];
    if (A * D < B * C) // 斜率要上升  如果不是上升，返回true
        return true;
    return false;
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
    ll n, dis, num, w, head, tail;
    cin >> n;
    head = tail = 0;
    q[tail++] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> dis >> num >> w;
        S[i] = num + S[i - 1];       // 产品数量 前缀和
        T[i] = num * dis + T[i - 1]; // 产品数量 * 距离前缀和

        // 判断head 是否优head +1 若非则移除head
        while (tail - head >= 2 && better(q[head + 1], q[head], dis))
            head++;

        // 此时最优方案是head
        dp[i] = dp[q[head]] + w + dis * (S[i] - S[q[head]]) - (T[i] - T[q[head]]);
        f[i] = dp[i] + T[i];
        // 判断尾部斜率
        while (tail - head >= 2 && slope(i, q[tail - 1], q[tail - 2]))
            tail--;
        q[tail++] = i;
    }

    ll ans = dp[n];
    for (ll i = n - 1; i >= 1 && S[i] == S[i + 1]; i--)
        ans = min(ans, dp[i]);
    cout << ans << endl;
    system("pause");
    return 0;
}