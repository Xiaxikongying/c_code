#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 500000
int dp[MAX_N + 5];
char s[MAX_N + 5];
vector<int> g[MAX_N + 5];

void extract(int i, int j)
{
    while (s[i] == s[j])
    {
        g[i].push_back(j - 1); //区间j-i是回文串，所以将j-1存g[i]中
        i++, j--;
    }
    return;
}

int main()
{
    cin >> (s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) //将所有的回文串存入相应的g[i]中（包含一个字符的回文串）
    {
        extract(i, i);     //以i为中心寻找回文串（字符个数为奇数的回文串）
        extract(i, i + 1); //以i和 i+1为中心，寻找回文串 （字符个数为偶数的回文串）
    }
    dp[0] = -1;
    for (int i = 1; s[i]; i++)
    {
        dp[i] = i;
        for (auto j : g[i])
        {
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n] << endl;
    system("pause");
    return 0;
}
