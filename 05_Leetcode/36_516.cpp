class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));

        // 单个字符是长度为1的回文子序列
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for (int l = 2; l <= n; ++l)
        {
            // l是子序列的长度
            for (int i = 0; i <= n - l; ++i)
            {
                int j = i + l - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};
