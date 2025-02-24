#include <iostream>
using namespace std;

int dp[105][105] = {0};  //用于存储人数
int dpt[105][105] = {0}; //用于存储时间
struct data
{
    int r1, r2, t;
};
data d[105];
/*
P1509 找啊找啊找GF
4
1 2 5
2 1 6
2 2 2
2 2 3
5 5
*/
int main()
{
    int n, R1, R2;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i].r1 >> d[i].r2 >> d[i].t;

    cin >> R1 >> R2;
    for (int i = 1, r1, r2, t; i <= n; i++)
    {
        r1 = d[i].r1, r2 = d[i].r2, t = d[i].t;
        for (int a = R1; a >= r1; a--)
        {
            for (int b = R2; b >= r2; b--)
            {
                if (dp[a][b] < dp[a - r1][b - r2] + 1)
                {
                    dp[a][b] = dp[a - r1][b - r2] + 1;
                    dpt[a][b] = dpt[a - r1][b - r2] + t;
                }
                else if (dp[a][b] == dp[a - r1][b - r2] + 1)
                    dpt[a][b] = min(dpt[a][b], dpt[a - r1][b - r2] + t);
            }
        }
    }
    cout << dpt[R1][R2] << endl;

    system("pause");
    return 0;
}
