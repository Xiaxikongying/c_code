#include <iostream>
using namespace std;

double myPow(double x, long long n)
{
    int flag = 1;
    if (n == 0)
        return 1;
    if (n < 0)
    {
        n = -n;
        flag = 0;
    }

    double ans = 1;
    while (n != 0)
    {
        if (n & 1)
            ans *= x;
        x *= x;
        n >>= 1;
    }
    if (flag)
        return ans;
    else
        return 1.0 / ans;
}
// 13 = 1 + 4 + 8

//--------------------------------------------------------------------------------------------------
// 也可以用递归来设计

// 13 = 6 +3 + 1 + 1+1
double powDiGui(double x, long long n)
{
    if (n == 1)
        return x;
    if (n % 2 == 1)
    {
        double half = powDiGui(x, n / 2);
        return half * half * x;
    }
    else
    {
        double half = powDiGui(x, n / 2);
        return half * half;
    }
}

double mypow2(double x, long long n)
{
    if (x == 1 || n == 0)
        return 1;
    if (n < 0)
        return 1.0 / powDiGui(x, -n);
    else
        return powDiGui(x, n);
}

int main()
{
    int a, n;
    while (cin >> a >> n)
        cout << mypow0(a, n) << endl;

    system("pause");
    return 0;
}