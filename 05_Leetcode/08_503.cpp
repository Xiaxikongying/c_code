class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n, -1);

        for (int i = 0; i < n * 2 - 1; i++)
        {
            while (!s.empty() && nums[i % n] > nums[s.top()])
            {
                ans[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return ans;
    }
};