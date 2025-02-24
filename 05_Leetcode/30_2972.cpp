class Solution
{
public:
    long long incremovableSubarrayCount(vector<int> &nums)
    {
        int left = 0;
        int len = nums.size();

        for (int i = 1; i < len; i++)
        {
            if (nums[i] > nums[i - 1])
                left++;
            else
                break;
        }
        if (left == len - 1)
            return len * (len + 1) / 2;

        long long ans = left + 2;
        for (int right = len - 1; right > 0; right--)
        {
            if (right != len - 1 && nums[right] >= nums[right + 1]) // 后半部分不是递增
                break;

            while (left >= 0 && nums[left] >= nums[right]) //left一定要小于right
            {
                --left;
            }
            ans += left + 2;
        }
        return ans;
    }
};