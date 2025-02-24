#include <iostream>
using namespace std;
/*
P1507 NASA的食物计划
320 350
4
160 40 120
80 110 240
220 70 310
40 400 220
*/
int dp[405][405] = {0};

int main()
{
    int H, T, n;
    cin >> H >> T >> n; //最大体积  最大质量   个数
    for (int i = 1, h, t, k; i <= n; i++)
    {
        cin >> h >> t >> k;
        for (int a = H; a >= h; a--)
        {
            for (int b = T; b >= t; b--)
                dp[a][b] = max(dp[a][b], dp[a - h][b - t] + k);
        }
    }
    cout << dp[H][T] << endl;
    system("pause");
    return 0;
}
