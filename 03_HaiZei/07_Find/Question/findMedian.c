/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
*/
// leetcode  04
#include <cinttypes>
class Solution
{
public:
    int findk(vector<int> &n1, int ind1, vector<int> &n2, int ind2, int k)
    {
        int n = n1.size(), m = n2.size();
        if (k == 1)
        {
            int a = (n1.size() == ind1 ? INT32_MAX : n1[ind1]);
            int b = (n2.size() == ind2 ? INT32_MAX : n2[ind2]);
            return min(a, b);
        }
        if (ind1 == n)
            return n2[k - 1];
        if (ind2 == m)
            return n1[k - 1];

        int cnt1 = min(k / 2, n - ind1);
        int cnt2 = min(k - cnt1, m - ind2);
        cnt1 = k - cnt2;

        if (n1[ind1 + cnt1 - 1] <= n2[ind2 + cnt2 - 1])
            return findk(n1, ind1 + cnt1, n2, ind2, k - cnt1);
        else
            return findk(n1, ind1, n2, ind2 + cnt2, k - cnt2);
    }

    
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        if ((n + m) % 2 == 1)
            return findk(nums1, 0, nums2, 0, (n + m) / 2 + 1);
            
        else{
            double a = findk(nums1, 0, nums2, 0, (n + m) / 2 + 1);
            double b = findk(nums1, 0, nums2, 0, (n + m) / 2);
            return (a + b) / 2.0;
        }
    }
};