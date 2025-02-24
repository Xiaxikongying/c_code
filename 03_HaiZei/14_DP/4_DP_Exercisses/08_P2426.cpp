#include <iostream>
using namespace std;

int dp[105]; //表示前i个数字可以得到的最大操作值
int arr[105] = {0};
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = dp[i - 1] + arr[i]; //单独处理i自成一段的情况
        for (int j = 1; j < i; j++) //假设[j~i]是最后一段
        {
            dp[i] = max(dp[i], dp[j - 1] + abs(arr[i] - arr[j]) * (i - j + 1));
        }
    }

    cout << dp[n] << endl;
    system("pause");
    return 0;
}
