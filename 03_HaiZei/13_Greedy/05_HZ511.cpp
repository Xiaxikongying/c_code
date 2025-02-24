#include <iostream>
#include <map>
using namespace std;

//最小操作次数
/*
2 10 2
3
*/

int fun(int a, int b, int k)
{
    if (a == b)
        return 0;
    if (k == 1)
        return (b - a);
    if (k == 0)
    {
        if (b == 0)
            return 1;
        else
            return (b - a);
    }

    int cnt = 0;
    while (1)
    {
        if (a * k <= b)
        {
            cnt += 1 + b % k;
            b /= k;
        }
        else
        {
            cnt += b - a;
            break;
        }
    }
    return cnt;
}

int main()
{
    int a, b, c;
    cin >> a, b, c;
    int d = fun(a, b, c);
    cout << d << endl;

    system("pause");
    return 0;
}
