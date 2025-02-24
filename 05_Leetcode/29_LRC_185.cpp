class Solution
{
public:
    vector<double> statisticsProbability(int n)
    {
        vector<double> ans;
        vector<double> dp(7, 1.0 / 6.0);

        for (int i = 2; i <= n; ++i)
        {
            int size = (i - 1) * 6;
            vector<double> tmp(i * 6, 0);
            for (int j = 0; j <= size - 1; ++j)
            {
                for (int k = 0; k < 6; ++k)
                {
                    tmp[j + k] += dp[j] / 6.0;
                }
            }
            dp = tmp;
        }
        while (dp.back() == 0.0)
            dp.pop_back();
        return dp;
    }
};