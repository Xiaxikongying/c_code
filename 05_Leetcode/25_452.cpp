class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;
        sort(points.begin(), points.end(),
             [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int n = points.size();

        int right = points[0][1];
        int pos = 1;
        int ans = 1;
        while (pos < n)
        {
            if (points[pos][0] > right)
            {
                right = points[pos][1];
                ++ans;
            }
            ++pos;
        }
        return ans;
    }
};