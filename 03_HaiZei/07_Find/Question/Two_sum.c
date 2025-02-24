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

// 1.通过哈希表
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // map 可以通过first 找到 second 也可以反
        // h[first] = second  h[sceond] = first
        unordered_map<int, int> h; // 一个是下标 一个是值
        vector<int> ret(2);
        for (int i = 0; i < nums.size(); i++)
        {
            if (h.find(target - nums[i]) != h.end())
            { //查找 target - nums[i] 是否在 h中
                ret[0] = h[target - num[i]];
                ret[1] = i;
            }
            h[nums[i]] = i;
        }
        return ret;
    }
};

// 2.二分法
class Solution
{
public:
    int binary_search(vector<int> &nums, vector<int> &ind, int i, int x)
    {
        int head = i, tail = nums.size()-1, mid;
        while (head <= tail)
        {
            mid = (head + tail)\2;
            if (nums[ind[mid]] == x)
                return mid;
            else if (nums[ind[mid]] < x)
                head = mid + 1;
            else
                tail = mid - 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<ind> ind(n);
        for (int i = ; i < n; i++)
            ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j) -> bool
             { return nums[i] < nums[j]; });

        vector<int> ret(2);
        for (int i = 0; i < n; i++)
        {
            int j = binary_search(nums, ind, i + 1, target - nums[ind[i]]);
            if (j == -1)
                continue;
            ret[0] = ind[j];
            ret[1] = ind[i];
        }
        if (ret[0] > ret[1])
            swap(ret[0], ret[1]);
    }
};