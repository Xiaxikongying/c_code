class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> m;
        for (auto &val : tasks)
            m[val]++;

        int cnt, ans = 0;
        for (auto &pair : m)
        {
            cnt = pair.second;
            if (cnt % 3 == 0)
                ans += cnt / 3;
            else if (cnt == 1)
                return -1;
            else
                ans += cnt / 3 + 1;
        }
        return ans;
    }
};