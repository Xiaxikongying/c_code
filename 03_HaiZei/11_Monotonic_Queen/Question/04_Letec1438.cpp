class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> qmax;
        deque<int> qmin;
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < nums.size(); right++)
        {
            while (!qmax.empty() && nums[qmax.back()] < nums[right])
                qmax.pop_back();
            qmax.push_back(right);

            while (!qmin.empty() && nums[qmin.back()] > nums[right])
                qmin.pop_back();
            qmin.push_back(right);

            while (nums[qmax.front()] - nums[qmin.front()] > limit)
            {
                //滑动窗口头部向后移动(left++) 直到移动的破坏平衡的值为止(找到并将其pop掉)
                if (left == qmax.front())
                    qmax.pop_front();
                if (left == qmin.front())
                    qmin.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};