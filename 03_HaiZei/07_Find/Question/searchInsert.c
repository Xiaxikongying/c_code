/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法
输入: nums = [1,3,5,6], target = 5
输出: 2
输入: nums = [1,3,5,6], target = 2
输出: 1

*/

// leetcode 35. 搜索插入位置

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int head = 0, tail = nums.size(), mid;
        while (head < tail)
        {
            mid = (tail + head) / 2;
            if (nums[mid] < target)
                head = mid + 1;
            else
                tail = mid;
        }
        return head;
    }
};