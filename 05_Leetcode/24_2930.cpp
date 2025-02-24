class Solution
{
public:
    long long mod = 1000000007;
    long long myPow(long long x, long long n)
    {
        long long ans = 1;
        while (n != 0)
        {
            if (n & 1)
                ans = (ans * x) % mod;
            x = (x * x) % mod;
            n >>= 1;
        }
        return ans;
    }

    int stringCount(int n)
    {
        if (n < 4)
            return 0;
        long long a, b, ab, ac, abc; // a 表示没有l / t     b 表示没有2个e---->有0个  或  1个e
        a = myPow(25, n);
        b = myPow(25, n) + n * myPow(25, n - 1);
        ab = myPow(24, n);
        ac = myPow(24, n) + n * myPow(24, n - 1);
        abc = myPow(23, n) + n * myPow(23, n - 1);

        long long res = (2 * a + b - ab - ac * 2 + abc) % mod;
        long long sum = myPow(26, n);
        long long ans = (sum + mod - res) % mod;
        return ans;
    }
};