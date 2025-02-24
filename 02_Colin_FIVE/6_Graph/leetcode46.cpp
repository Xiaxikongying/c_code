// leetcode 46 全排列
class Solution
{
public:
    int vis[21];
    // ans 接收结果的  nums传入数据  n递归深度 arr存放本次结果
    void meiju(vector<vector<int>> &ans, vector<int> &nums, int n, vector<int> &arr)
    {
        if (n == nums.size())
        {
            ans.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[nums[i] + 10] == 1)
                continue;
            arr[n] = nums[i];
            vis[nums[i] + 10] = 1;
            meiju(ans, nums, n + 1, arr); // n+1表示该函数枚举的是下一位
            vis[nums[i] + 10] = 0;
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n);
        vector<vector<int>> ans;
        meiju(ans, nums, 0, arr);
        return ans;
    }
};