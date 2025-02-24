class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &heights)
    {
        int n = heights.size();
        vector<long long> pre(n), suf(n);
        stack<long long> s1, s2;
        long long ans = 0;

        for (long long i = 0; i < n; i++)
        {
            while (!s1.empty() && heights[i] < heights[s1.top()])
                s1.pop();
            if (s1.empty())
                pre[i] = (i + 1) * heights[i];
            else
                pre[i] = pre[s1.top()] + (i - s1.top()) * heights[i];
            s1.push(i);
        }

        for (long long i = n - 1; i >= 0; i--)
        {
            while (!s2.empty() && heights[i] < heights[s2.top()])
                s2.pop();
            if (s2.empty())
                suf[i] = (n - i) * heights[i];
            else
                suf[i] = suf[s2.top()] + (s2.top() - i) * heights[i];
            s2.push(i);

            ans = max(ans, pre[i] + suf[i] - heights[i]);
        }
        return ans;
    }
};