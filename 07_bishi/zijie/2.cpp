#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2005;
const long long INF = -1e18; // 代表极小值
vector<long long> a(MAXN), prefixSum(MAXN), dp(MAXN);

int main()
{
    int n, q;
    cin >> n >> q;

    // 输入数组
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // 计算前缀和
    prefixSum[0] = 0;
    for (int i = 1; i <= n; ++i)
        prefixSum[i] = prefixSum[i - 1] + a[i];

    // 预处理每种长度的子数组的最大和
    for (int len = 1; len <= n; ++len)
    {
        long long cur_sum = INF;
        for (int i = 1; i + len - 1 <= n; ++i)
        {
            int j = i + len - 1;                                 // 子数组右边界
            long long sub_sum = prefixSum[j] - prefixSum[i - 1]; // 子数组和
            cur_sum = max(cur_sum, sub_sum);                     // 更新最大值
        }
        dp[len] = cur_sum;
    }

    // 处理查询
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        long long res = INF;
        // 查询长度区间 [l, r] 内的最大子数组和
        for (int len = l; len <= r; ++len)
            res = max(res, dp[len]);
        cout << res << endl;
    }
    system("pause");
    return 0;
}

/*
小红有一个长度为n的数组α1，a2,....an，她每次会询问一个区间[l,r]，她想知道数组a的所有长度大于等于l且小于等于r的子数组之和的最大值是多少。
如果数组a可以通过从数组b的开头删除若干（可能为零或全部）元素以及从结尾删除若干（可能为零或全部）元素得到，则数组α是数组b的子数组
输入描述:
第一行输入两个整数n和q（1≤n≤2000;1≤q≤10^6）代表数组中的元素数量和询问次数。
第二行输入n个整数
α1,α2,...,an（-10^9≤a≤10^9）代表数组元素。
此后q行，每行输入两个整数l,r,(1≤l≤r≤n)代表询问的长度区间。
输出描述:
对于每个询问，在一行上输出一个整数代表答案。
示例1:
输入:
3 2
1 2 -1
1 2
3 3
输出:
3
2
说明:对于第一个询问，长度为1的子数组有：{1}{2}和{-1}；长度为2的子数组有：{1,2}、{2，一1}，这五个数组和的最大值为max{1,2,-1,1+2,2-1}=3。

示例2:
输入:
5 3
1 2 3 4 5
1 1
1 2
1 3
输出:
5
9
12
用C++写出上述程序

*/