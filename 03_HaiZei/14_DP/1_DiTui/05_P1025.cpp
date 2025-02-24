#include <iostream>
#include <math.h>
using namespace std;

/*
P1025 数的划分
将整数 n 分成k 份，且每份不能为空，任意两个方案不相同 (不考虑顺序)
例如: n = 7，k =3，下面三种分法被认为是相同的
7 3
4

四种分法为：
1 1 5
1 2 4
1 3 3
2 2 3
*/
int f[205][7] = {0}; //  钱  步数

int main()
{
    int n, k;
    cin >> n >> k;
 
    for (int i = 1; i <= n; i++)
        f[i][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            if (j <= i)
                f[i][j] = f[i - 1][j - 1] + f[i - j][j];
        }
    }
    cout << f[n][k] << endl;

    system("pause");
    return 0;
}
/*
将总方法数分为有1的   和  没有1的
有1的--->= f[i-1][j-1] 将那一位1删去
没有1的--->=f[i-j][j] 全部位数的数字全部减去1
*/