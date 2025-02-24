class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int sum = (n + m) * mean;
        for (int i = 0; i < m; i++)
            sum -= rolls[i];
        vector<int> ans;

        if (n * 6 < sum || n > sum)
            return ans;
        int a = sum / n;
        int b = sum % n;

        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x = a + (i < b);
            ans.push_back(x);
        }
        return ans;
    }
};