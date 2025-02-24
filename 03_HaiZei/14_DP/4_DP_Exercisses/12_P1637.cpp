#include <iostream>
using namespace std;

int arr[30005];
int dp[30005][2];
int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i][0] += 1;//求i处二元上升序列的值
                dp[i][1] += dp[j][0];//i处三元上升序列的值
            }
        }
        ans += dp[i][1];
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
