/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/

// leetcode 88
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1, k = n + m - 1;
        while (p1 >= 0 || p2 >= 0)
        {
            if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2]))
            {
                nums1[k] = nums1[p1];
                k--;
                p1--;
            }
            else{
                nums1[k] = nums2[p2];
                k--;
                p2--;
            }
        }
    }
};