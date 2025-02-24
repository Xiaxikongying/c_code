int MOD = 1e9 + 7;
int numberOfWays(int startPos, int endPos, int k)
{
    // write code here
    int n = abs(startPos - endPos);
    if (n > k || (k - n) % 2 != 0)
        return 0;
    vector<vector<int>> dp(k + 1, vector<int>(2 * k + 1, 0));
    dp[0][k] = 1;
    for (int i = 1; i <= k; ++i) // i表示步数
    {
        for (int j = 1; j < 2 * k; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
    }
    return dp[k][endPos - startPos + k];
}