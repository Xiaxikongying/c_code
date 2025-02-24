class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int prev = max(arr[0], arr[1]);
        if (k == 1)
            return prev;

        int time = 1;
        int max = prev, cur;
        int length = arr.size();
        for (int i = 2; i < length; i++)
        {
            cur = arr[i];
            if (prev > cur)
            {
                time++;
                if (time == k)
                    return prev;
            }
            else
            {
                prev = cur;
                time = 1;
            }
            max = max(max, cur);
        }
        return max;
    }
};