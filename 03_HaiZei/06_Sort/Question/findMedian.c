/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
*/
// leetcode  04

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> temp(n + m);
        int p1 = 0, p2 = 0, k = 0;
        while (p1 < n || p2 < m)
        {
            if (p2 == m || (p1 < n && nums1[p1] < nums2[p2]))
                temp[k++] = nums1[p1++];
            else
                temp[k++] = nums2[p2++];
        }

        double a = temp[(n + m / 2)];
        if ((n + m) % 2 == 1)
            return a;
        else
        {
            double b = temp[(n + m) / 2 - 1];
            return (a + b) / 2;
        }
    }
};