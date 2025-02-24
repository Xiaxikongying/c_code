#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005;

vector<int> BIT(MAXN, 0); // 树状数组，初始化为0

// 更新树状数组，在位置index加上value
void update(int index, int value, int n)
{
    while (index <= n)
    {
        BIT[index] = (BIT[index] + value) % MOD;
        index += index & -index; // BIT的更新规则
    }
}

// 查询树状数组，返回从1到index的和
int query(int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum = (sum + BIT[index]) % MOD;
        index -= index & -index; // BIT的查询规则
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), sorted_a(n);

    // 输入数组
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sorted_a[i] = a[i];
    }

    // 离散化处理
    sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

    // dp数组，用于存储每个元素以其结尾的递减子序列数量
    vector<int> dp(n, 1); // 初始化为1，表示每个元素自身作为长度为1的递减子序列

    long long res = 0; // 最终结果

    for (int i = 0; i < n; ++i)
    {
        // 离散化，将a[i]映射到一个较小的索引
        int index = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;

        // 查询树状数组，获取所有比a[i]大的数的递减子序列数量和
        dp[i] = (dp[i] + query(n) - query(index)) % MOD;

        // 更新树状数组，在index处加上dp[i]的值
        update(index, dp[i], n);

        // 更新结果
        res = (res + dp[i]) % MOD;
    }

    cout << res << endl;
    system("pause");
    return 0;
}

/*
小红有一个长度为n的数组a1，a2，..，an，请你帮助她求出有多少个严格单调递减的子序列。结果可能很大，对10^9+7取模后再输出。
严格单调递减序列:是指一个序列满足：长度为1或从第2项开始，每一项均小于前一项的序列。
由原来的序列删除（或不删除）某些元素而不改变其余元素的相对顺序的序列称为子序列。
输入描述:
第一行输入-个整数n（1≤n≤2·10）代表数组中的元素数量。
第二行输入n个整数a1,a2,...,an（1≤a≤10^9)代表元素。
输出描述:
在一行上输出一个整数，代表严格单调递减的子序列的个数，由于数据较大，输出答案对10^9+7取模的结果。
示例1:
输入:
4
1 3 5 2
输出:6
说明:由两个元素构成的满足题意的子序列为{3,2}、{5,2}
*/