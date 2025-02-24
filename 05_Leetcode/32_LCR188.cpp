class Solution
{
public:
    int bestTiming(vector<int> &prices)
    {
        int Max = 0;
        int ind = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if(prices[i+1] >= prices[ind])
                Max = max(Max,prices[i + 1] - prices[ind]);
            else
                ind = i + 1;
        }
        return Max;
    }
};