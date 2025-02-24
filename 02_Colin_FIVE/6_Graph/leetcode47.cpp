// leetcode 47 全排列 II
class Solution
{
public:
    int vis[23];
    void meiju(vector<vector<int>> &ans, vector<int> &nums, int n, vector<int> &arr)
    {
        if (n == nums.size())
        {
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] == arr)
                    return;
            }
            ans.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i] == 1)
                continue;
            arr[n] = nums[i];
            vis[i] = 1;
            meiju(ans, nums, n + 1, arr); // n+1表示该函数枚举的是下一位
            vis[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n);
        vector<vector<int>> ans;
        meiju(ans, nums, 0, arr);
        return ans;
    }
};