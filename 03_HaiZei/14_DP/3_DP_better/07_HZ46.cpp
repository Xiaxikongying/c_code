#include <iostream>
#include <cstring>
using namespace std;

char s[100005];
int dp[100005];
// dp[i] 表示从1 到 i 需要切几刀
// sehuhzzexe-------->4

bool is_palindrome(int i, int j) //判断区间ij是不是回文串
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++,j--;
    }
    return true;
}

int main()
{
    cin >> (s + 1);
    int n = strlen(s + 1);
    dp[0] = -1;  //不切的话，就不需要+1，dp[0] = -1 就是为了抵消
    for (int i = 2; i <= n; i++)
    {
        dp[i] = i - 1; //先赋值上最坏的情况
        // j == 0 ---->不切，看看dp[i]的值
        for (int j = 0; j < i; j++) //试从j处切开，看j-i是不是回文串
        {
            if (is_palindrome(j + 1, i)) //若切割后 后面有回文串，则是有效切割
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    cout << dp[n] << endl;
    system("pause");
    return 0;
}
