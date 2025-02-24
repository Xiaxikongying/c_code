/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
*/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> h;
        vector<int> ret;
        for (auto x : nums1)
            h.insert(x);
        for (auto x : nums2)
        {
            if (h.find(x) == h.end())
                continue;
            ret.push_back(x);
            h.erase(h.find(x));
        }
        return ret;
    }
};

// 2
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ret;
        int a[10001] = {0};
        for (int i = 0; i < nums1.size(); i++)
            a[nums1[i]] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (a[nums2[i]] == 1)
            {
                ret.push_back(nums2[i]);
                a[nums2[i]] = 0;
            }
        }
        return ret;
    }
};