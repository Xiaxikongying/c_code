/*
leetcode 1 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。


输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
只会存在一个有效答案

*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++)
            ind[i] = i;
        sort(ind.begin(), ind.end(),
             [&](int i, int j) -> bool
             { return nums[i] < nums[j]; });

        int p1 = 0, p2 = n - 1;
        while (nums[ind[p1]] + nums[ind[p2]] != target)
        {
            if (nums[ind[p1]] + nums[ind[p2]] < target)
                p1++;
            else
                p2--;
        }
        vector<int> ret;
        ret[0] = ind[p1];
        ret[1] = ind[p2];
        if (ret[0] > ret[1])
            swap(ret[0], ret[1]);
        return ret;
    }
};