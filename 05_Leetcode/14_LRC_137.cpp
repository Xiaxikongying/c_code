class Solution
{
public:
    bool articleMatch(string A, string B)
    {
        int n = A.length();
        int m = B.length();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = (i == 0);
                    continue;
                }
                // B第j位不是 *
                if (B[j - 1] != '*')
                {
                    if (i >= 1 && (B[j - 1] == A[i - 1] || B[j - 1] == '.'))
                        dp[i][j] = dp[i - 1][j - 1];
                }
                else // B第j位是 *
                {
                    // 不管 x*  ---->视其出现0次
                    if (j >= 2)
                        dp[i][j] = dp[i][j - 2];

                    // x* ---->出现视其出现若干次（至少一次）
                    if (i >= 1 && (B[j - 2] == A[i - 1] || B[j - 2] == '.'))
                        dp[i][j] |= dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};