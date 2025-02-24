class Solution
{
public:
    int trainingPlan(vector<int> &actions)
    {
        int ans = 0;
        int num = 0;
        for (int i = 0; i < 32; i++)
        {
            num = 0;
            for (auto val : actions)
            {
                if ((val >> i) & 1)
                    ++num;
            }
            if (num % 3 == 1)
                ans += (1 << i);
        }
        return ans;
    }
};