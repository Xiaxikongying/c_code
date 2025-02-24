class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int ans = n;
        int time = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] != nums[i])
            {
                ans += time;
                ++time;
            }
            else
                time = 1;
        }
        return ans;
    }
};