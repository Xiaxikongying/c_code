class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        int sum = 0, max = 0;
        for (auto val : milestones)
        {
            sum += val;
            if (val > max)
                max = val;
        }
        sum -= max;

        if (max <= sum + 1)
            return sum + max;
        else
            return 2 * sum + 1;
    }
};