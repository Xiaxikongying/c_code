/*
260. 只出现一次的数字 III
给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        vector<int> ret(2);
        for (int i = 0; i < n; i++)
            ans ^= nums[i];

        int c = ans == INT_MIN ? 1 : (ans & (-ans)); //取得一个1的位置

        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] & c) == 0)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        ret[0] = a;
        ret[1] = b;
        return ret;
    }
};