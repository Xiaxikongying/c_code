#include <iostream>
#include <vector>
//
int findMin(const std::vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    // 使用二分查找法
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        // 如果中间元素小于右边界元素，最小值在左侧或是mid
        if (nums[mid] < nums[right])
            right = mid; // 保持 mid 有可能是最小值
        // 如果中间元素大于右边界元素，最小值在右半部分
        else if (nums[mid] > nums[right])
            left = mid + 1;
        // 当 nums[mid] == nums[right] 时，无法确定最小值在哪，缩小范围
        else
            right--;
    }
    // 最小值一定在 left 位置
    return nums[left];
}
/*
给定一个递增循环整数数组，从里面找出最小的元素，使用的算法越快越好。特别的，最小的元素可能出现在数组中间。如 50 52 63 90 3 8 15 44
用C++实现
*/