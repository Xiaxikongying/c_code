#include <iostream>
#include <math.h>
#include <map>
using namespace std;
#define MAX 17

double dis[MAX][MAX]; //例如dis[a][b]  就是从奶酪A到奶酪B的距离  下标0就是小鼠本身的位置
double x[MAX];        // xy是记录每个奶酪的位置
double y[MAX];
//因为 1 <= n <= 15   2^16 = 65535
double dp[70000][20] = {0}; // dp[t][now]  t是表示奶酪的状态(如11100100)-->0表示被吃了  1表示还存在
                            // now表示小鼠该次是在吃哪个奶酪
int n;
double ans = 1e9;
int ind[70000];
#define S(a) ((a) * (a))
double getDis(int i, int j)
{
    return sqrt(S(x[i] - x[j]) + S(y[i] - y[j]));
}

void dfs(int t, int now, double Dis) // t表示全部奶酪的状态，now表示当前小鼠在哪个奶酪处，dis表示现在走的距离
{
    if (t == 0)
    {
        if (Dis < ans)
            ans = Dis;
        return;
    }

    for (int i = t; i != 0; i -= (-i & i))
    {
        int j = ind[-i & i];   // j 表示本次要去吃的奶酪的下标
        int nt = t ^ (1 << j); //将吃掉奶酪的位置 变为0
        double D = Dis + dis[now][j];

        if (D >= ans)  //简单的枝剪法
            continue;
        if (dp[nt][j] != 0 && dp[nt][j] <= D) //枝剪法  将路径相同 当前位置也相同，但距离更长的分支剪去
            continue;
        dp[nt][j] = D;
        dfs(nt, j, D);
    }
    return;
}

int main()
{
    scanf("%d", &n); //奶酪个数
    double tx, ty;
    int t = (1 << (n + 1)) - 2; //状态编码
    //各个奶酪的位置
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &tx, &ty);
        x[i] = tx;
        y[i] = ty;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
            dis[i][j] = dis[j][i] = getDis(i, j);
    }

    for (int i = 0, k = 1; i <= n; i++, k *= 2)
        ind[k] = i;

    dfs(t, 0, 0);
    printf("%.2lf\n", ans);
    system("pause");
    return 0;
}
