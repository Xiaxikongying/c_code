#include <iostream>
using namespace std;

/*
P1058 传球
n个人围成一圈
m次传球 球只可以给边上的人
小明为1号，求m次后传回到小明手上的传球方法

3 3
2
*/
int f[35][35] = {0}; // f[i][j] 表示第j次传球到i号手中的方法次数

int main()
{
    // f[i][m] = f[i+1][m-1] + f[i-1][m-1]
    int n, m;
    cin >> n >> m;
    f[1][0] = f[2][1] = f[n][1] = 1;
    for (int j = 2; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int a = (i + 1 == n + 1) ? 1 : i + 1;
            int b = (i - 1 == 0) ? n : (i - 1);
            f[i][j] = f[a][j - 1] + f[b][j - 1];
        }
    }
    cout << f[1][m] << endl;
    system("pause");
    return 0;
}
