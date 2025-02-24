// leetcode 42. 接雨水

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++) //找left的较大值
        {
            while (!s.empty() && height[s.top()] < height[i])
            {
                right[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        if (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--) //找right的较大值
        {
            while (!s.empty() && height[s.top()] <= height[i])
            {
                left[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        int ans = 0;
        int h, w;
        for (int i = 0; i < n; i++)
        {
            if (left[i] == -1 || right[i] == -1)
                continue;

            h = min(height[left[i]], height[right[i]]) - height[i];
            w = right[i] - left[i] - 1;
            ans += h * w;
        }
        return ans;
    }
};
//-------------------------------------------------------------------
//方法二
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < n; i++) //找left的较大值
        {
            while (!s.empty() && height[s.top()] < height[i])
            {
                int h_min = height[s.top()];
                s.pop();
                if (s.empty())
                    break;
                int h = min(height[i], height[s.top()]) - h_min;
                ans += h * (i - s.top() - 1);
            }
            s.push(i);
        }
        return ans;
    }
};