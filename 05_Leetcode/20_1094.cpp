class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> num(1005, 0);
        int n = trips.size();
        for (int i = 0; i < n; i++)
        {
            num[trips[i][1]] += trips[i][0];
            num[trips[i][2]] -= trips[i][0];
        }
        int sum = 0;
        for (int i = 0; i <= 1000; i++)
        {
            sum += num[i];
            if (sum > capacity)
                return false;
        }
        return true;
    }
};