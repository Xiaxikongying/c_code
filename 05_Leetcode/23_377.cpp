class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<double> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (auto e : nums)
            {
                if (i >= e)
                    dp[i] += dp[i - e];
            }
        }
        return dp[target];
    }
};