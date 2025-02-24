#include <iostream>
using namespace std;

/*
P1541 乌龟棋
输入一个数字N，M，
N表示一共有N个格子，然后给每个格子输入相应的分数
M表示卡牌的数量，然后输入每一张卡牌的数字（前进的格数），一共只有1234种情况
求到达终点的最高分

输入数据保证到达终点时刚好用光 M 张爬行卡片。
9 5
6 10 14 2 8 8 18 5 17
1 3 1 2 1
*/
#define Max 45
int cnt[5] = {0};
int dp[Max][Max][Max][Max] = {0};
// dp[a][b][c][d]---->表示各个卡片用ab..张最高的分数
int val[355] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    //输入每个格子的分数
    for (int i = 0; i < n; i++)
        cin >> val[i];
    //输入卡牌
    for (int i = 1, t; i <= m; i++)
    {
        cin >> t;
        cnt[t]++;
    }


    //更新数据
    for (int a = 0; a <= cnt[1]; a++)
    {
        for (int b = 0; b <= cnt[2]; b++)
        {
            for (int c = 0; c <= cnt[3]; c++)
            {
                for (int d = 0; d <= cnt[4]; d++)
                {
                    int s = a + b * 2 + c * 3 + d * 4;
                    int ans = 0;
                    if (a != 0)
                        ans = max(ans, dp[a - 1][b][c][d]);
                    if (b != 0)
                        ans = max(ans, dp[a][b - 1][c][d]);
                    if (c != 0)
                        ans = max(ans, dp[a][b][c - 1][d]);
                    if (d != 0)
                        ans = max(ans, dp[a][b][c][d - 1]);

                    dp[a][b][c][d] = ans + val[s];
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;

    system("pause");
    return 0;
}

