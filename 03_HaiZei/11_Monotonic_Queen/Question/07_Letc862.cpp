// leetcode 862  和至少为k的最短子序列
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = nums[i - 1] + sum[i - 1];
        deque<int> q;
        int ans = n + 1;
        q.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            while (!q.empty() && sum[i] - sum[q.front()] >= k)
            {
                ans = min(ans, i - q.front());
                q.pop_front();
            }

            while (!q.empty() && sum[q.back()] > sum[i])
                q.pop_back();
            q.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
};