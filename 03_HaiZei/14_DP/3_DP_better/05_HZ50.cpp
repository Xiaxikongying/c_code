#include <iostream>
#include <math.h>
using namespace std;
/*
定义鸡蛋的硬度为 k，则代表鸡蛋最高从 k 楼扔下来不会碎掉，
现在给你 n 个硬度相同的鸡蛋，楼高为 m，问最坏情况下最少测多少次，可以测出鸡蛋的硬度。
输入为 个数N  层数 M
2 100 ----> 14
1 5  ---->5

最坏情况下最少测多少次---->在最优的测试方案下，最多的测试次数

*/
int dp[35][100000] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)//只有一个鸡蛋  i层楼，dp[1][i] = i
        dp[1][i] = i;
    for (int i = 1; i <= n; i++)//只有1层楼，只能测一次  dp[i][1] = 1
        dp[i][1] = 1;

    for (int i = 2; i <= n; i++) //遍历每个鸡蛋
    {
        for (int j = 2; j <= m; j++) //遍历每一层楼
        {
            dp[i][j] = j;//先以最坏的打算给dp赋值
            for (int k = 1; k <= j; k++) //假设将 鸡蛋i 从k层楼扔下，每一层都测试一下，看看从那一层扔下鸡蛋的方案最优
                dp[i][j] = min(dp[i][j], max(dp[i][j - k], dp[i - 1][k - 1]) + 1);
        }
    }

    cout << dp[n][m] << endl;
    /*
    dp[i][j - k]---->如果鸡蛋没碎，则需要用i个鸡蛋 测试上面的楼层（j-k）
    dp[i - 1][k - 1]---->如果鸡蛋碎了，则需要用i-1个鸡蛋测试下面的k-1层楼
    */
    system("pause");
    return 0;
}
