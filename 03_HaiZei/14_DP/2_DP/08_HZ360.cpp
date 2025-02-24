#include <iostream>
using namespace std;

/*
HZ_360 棋盘切割
3
1 1 1 1 1 1 1 3
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 1 1 1 1 0 3
1460
*/

int val[10][10] = {0};
int dp[20][10][10][10][10] = {0};
// dp[n][i][j][k][l]  表示矩阵（i，j）--->(k,l) 切分成n块的最小平方和
#define INF 0x3f3f3f3f

int getVal(int i, int j, int k, int l)
{
    int v = val[k][l] - val[i - 1][l] - val[k][j - 1] + val[i - 1][j - 1];
    return v * v;
}

int main()
{
    int n;
    cin >> n;
    //输入数据
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            cin >> val[i][j];
            val[i][j] += val[i - 1][j] + val[i][j - 1] - val[i - 1][j - 1];
        }
    }

    //初始化dp数据
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            for (int k = 1; k <= 8; k++)
            {
                for (int l = 1; l <= 8; l++)
                    dp[1][i][j][k][l] = getVal(i, j, k, l);
            }
        }
    }

    //分割矩阵
    for (int t = 2; t <= n; t++) //最少分成2块
    {
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                for (int k = 1; k <= 8; k++)
                {
                    for (int l = 1; l <= 8; l++) //遍历每一个矩阵
                    {
                        int ans = INF;
                        for (int c = i; c <= k; c++) //横向切割  从c = i开始切割
                        {
                            int v1 = dp[1][i][j][c][l] + dp[t - 1][c + 1][j][k][l];
                            int     
                            ans = min(ans, min(v1, v2));
                        }

                        for (int c = j; c <= k; c++) //竖向切割  从c = i开始切割
                        {
                            int v1 = dp[1][i][j][k][c] + dp[t - 1][i][c + 1][k][l];
                            int v2 = dp[t - 1][i][j][k][c] + dp[1][i][c + 1][k][l];
                            ans = min(ans, min(v1, v2));
                        }
                        dp[t][i][j][k][l] = ans;
                    }
                }
            }
        }
    }
    cout << dp[n][1][1][8][8] << endl;
    system("pause");
    return 0;
}
