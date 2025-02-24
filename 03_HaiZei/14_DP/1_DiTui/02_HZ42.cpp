#include <iostream>
#include <vector>
using namespace std;
// haizeioj 42 凑钱币
/*
8 200
1 2 5 10 20 50 100 200
3871
*/

int money[25];
int f[25][10000] = {0};//f[i][j] 表示只用钱i中钱币  凑到j元的方法数量

int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> money[i];
    
    for (int i = 1; i <= m; i++) // m是钱的种数
    {
        f[i][0] = 1;
        for (int j = 1; j <= n; j++) // n是需要凑的钱数
        {
            f[i][j] = f[i - 1][j];//没用钱币i就凑到了j元的方法数
            
            if (j < money[i])
                continue;
            f[i][j] += f[i][j - money[i]]; //使用了money 就凑到了n元的方法
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;

    system("pause");
    return 0;
}
