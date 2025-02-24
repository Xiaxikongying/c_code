/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。

leetcode 264
*/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        set<long long> s;
        s.insert(1);
        long long ans;
        int flag = 0;
        while (n--)
        {
            ans = *s.begin();
            s.erase(s.begin());

            if (ans % 5 == 0) // 最大质因子为5
                s.insert(ans * 5);
            else if (ans % 3 == 0) // 最大质因子为3
            {
                s.insert(ans * 3);
                s.insert(ans * 5);
            }
            else // 最大质因子为2
            {
                s.insert(ans * 2);
                s.insert(ans * 3);
                s.insert(ans * 5);
            }
            /*
            if (ans % 5 == 0)
                flag = 2;
            else if (ans % 3 == 0)
                flag = 1;
            else
                flag = 0;
            switch (flag)
            {
            case 0:
                s.insert(ans * 2);
            case 1:
                s.insert(ans * 3);
            case 2:
                s.insert(ans * 5);
            }
            */
        }
        return ans;
    }
};