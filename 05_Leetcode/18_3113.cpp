class Solution
{
public:
    struct node
    {
        int val, ind;
        node(int a, int b) : val(a), ind(b) {}
    };
    long long numberOfSubarrays(vector<int> &nums)
    {
        long long ans = nums.size();
        stack<node> s;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!s.empty() && nums[i] > s.top().val)
                s.pop();
            if (!s.empty() && nums[i] == s.top().val)
                ans += s.top().ind++;
            else
                s.push(node(nums[i], 1));
        }
        return ans;
    }
};