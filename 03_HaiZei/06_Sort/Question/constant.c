/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
如果存在，返回 true ；否则，返回 false 。

输入：nums = [1,2,3,1], k = 3
输出：true
*/
// leetcode 219 存在重复的元素

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++)
            ind[i] = i;
        sort(ind.begin(), ind.end(),
             [&](int i, int j)
             {
                 if (nums[i] != nums[j])
                     return nums[i] < nums[j];
                 else
                     return i < j;
             });
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[ind[i]] != nums[ind[i + 1]])
                continue;
            if (ind[i + 1] - ind[i] <= k)
                return true;
        }
        return false;
    }
};