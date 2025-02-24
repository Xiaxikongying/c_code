/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

leetcode 128
*/
class UnionSet
{
public:
    vector<int> fa, size;
    UnionSet(int n) : fa(n + 1), size(n + 1)
    {
        for (int i = 0; i <= n; i++)
        {
            fa[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {return fa[x] = (fa[x] == x ? x : find(fa[x]));}

    int merge(int a, int b)
    {
        int aa = find(a);
        int bb = find(b);
        if (aa == bb)
            return 0;
        fa[aa] = bb;
        size[bb] += size[aa];
        return 1;
    }
};

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;  //下标
        unordered_map<int, int> h;
        UnionSet u(n);
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            if (h.find(x) != h.end()) //找到相同的数字
                continue;
            h[x] = cnt++;

            if (h.find(x + 1) != h.end())
                u.merge(h[x], h[x + 1]);

            if (h.find(x - 1) != h.end())
                u.merge(h[x], h[x - 1]);
        }

        int ans = 0;
        for (int i = 0; i < cnt; i++)
        {
            ans = max(ans, u.size[i]);
        }
        return ans;
    }
};