class Solution
{
public:
    int iceBreakingGame(int n, int m)
    {
        int x = 0;
        for (int i = 2; i <= n; ++i)
        {
            x = (x + m) % i;
        }
        return x;
    }
};