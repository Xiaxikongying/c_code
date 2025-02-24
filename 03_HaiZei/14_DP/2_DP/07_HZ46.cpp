#include <iostream>
#include <cstring>
using namespace std;

char s[100005];
int dp[100005][100005];
//dp[i][j] 表示区间i--j中最少切几刀使得ij为回文串
/*
sehuhzzexe
4
*/
int main()
{
    cin >> (s + 1);
    int n = strlen(s + 1);
    for (int l = 1; l <= n; l++) // l是区间的间距
    {
        for (int i = 1, j; i <= n - l + 1; i++) // i是开始的地方  j是结束的位置
        {
            j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 0) //判断区间 [i,j]是否是回文串
                dp[i][j] == 0;
            else
            {
                dp[i][j] = l; //先赋上最大值
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                    //后面这个数字是-->假设在k处切一刀，看左右两边是否有回文串
                    //但是由于切了一刀，所以要加1
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    system("pause");
    return 0;
}
