#include <iostream>
#include <math.h>
using namespace std;
/*
定义鸡蛋的硬度为 k，则代表鸡蛋最高从 k 楼扔下来不会碎掉，
现在给你 n 个硬度相同的鸡蛋，楼高为 m，问最坏情况下最少测多少次，可以测出鸡蛋的硬度。
输入为 个数N  层数 M
2 100 ----> 14
1 5  ---->5
*/

#define MAX_K 100000
long long dp[35][MAX_K] = {0};
/*
由于楼层的数量过高，最大数据足足有2^32次方，远远超过了题目的内存要求
而我们只能试着去改变 dp--->状态重新定义
在原来 dp[i][j] = k  表示i个鸡蛋 j层楼  用最优的方案 最多的测试次数为k

我们不如将楼层与次数交换位置
dp[i][k] = j  ----> 表示i个鸡蛋 k次测试  最多可以测试多少层楼

由于m 楼层是给出的，我们只需要从1开始遍历每一次测试，
就可以通过楼层得到 具体的测试次数
第k次测试由三部分组成：
dp[i][k] = 第k次没碎  + 第k次碎了(不论哪一种剩余的测试次数都是k-1次 ) + 第k次测试的楼层1
dp[i][k] = dp[i][k-1] + dp[i-1][k-1] + 1

*/
int main()
{
    long long n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << m << endl;
        return 0;
    }

    for (long long i = 1; i < MAX_K; i++)//只有1个鸡蛋，需要测i次，则说明有i层楼
        dp[1][i] = i;

    for (long long i = 2; i <= n; i++) //遍历每个鸡蛋
    {
        for (long long k = 1; k < MAX_K; k++) //遍历每一次测试
        {
            dp[i][k] = dp[i][k - 1] + dp[i - 1][k - 1] + 1;
            if (dp[i][k] >= m)
                break;
        }
    }

    long long k = 1;
    while (dp[n][k] < m)
        k++;

    cout << k << endl;
    system("pause");
    return 0;
}
