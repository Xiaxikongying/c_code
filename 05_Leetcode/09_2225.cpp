class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        int n = matches.size();
        vector<vector<int>> ans(2);
        map<int, int> flag;
        for (int i = 0; i < n; i++)
        {
            flag[matches[i][1]]++;
            if (flag.count(matches[i][0]) == 0)
                flag[matches[i][0]] = 0;
        }

        for (auto val : flag)
        {
            if (val.second == 0)
                ans[0].push_back(val.first);
            if (val.second == 1)
                ans[1].push_back(val.first);
        }
        return ans;
    }
};