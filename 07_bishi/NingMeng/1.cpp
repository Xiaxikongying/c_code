#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    

    // 定义一个dp数组，其中dp[j]表示和为j的组合数
    vector<int> dp(s + 1, 0);
    dp[0] = 1; // 和为0时，组合数为1（即什么都不选）

    // 遍历每个数字
    for (int i = 0; i < n; i++)
    {
        // 必须从后向前遍历，防止重复使用当前数字
        for (int j = s; j >= numbers[i]; j--)
            dp[j] += dp[j - numbers[i]];
    }

    cout << dp[s] << endl;
    system("pause");
    return 0;
}

/*
给定一个正整数s和n个正整数，求有多少种组合的和为s？
数值相同的两个数视为不同的两个数。
输入描述
第一行两个整数n，s，含义如题所述；
第二行n个整数。
1≤n≤30，1≤s≤900，1≤wi≤s。
输出描述
输出一个整数表示答案。特别地，如果没有合法方案，输出0。

测试数据
输入
10 5
1 1 1 1 1 1 1 1 1 1
输出
252
说明
C(10, 5)=252
*/