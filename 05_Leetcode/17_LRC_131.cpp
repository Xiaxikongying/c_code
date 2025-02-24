class Solution
{
public:
    int cuttingBamboo(int len)
    {
        vector<int> dp(len + 1);
        for (int i = 1; i <= len; i++)
        {
            for (int j = 2; j < i; j++)
                dp[i] = max(max(dp[i - j] * j, (i - j) * j), dp[i]);
        }
        return dp[len];
    }
};