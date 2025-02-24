#include <iostream>
using namespace std;

//10进制转8进制

int main()
{
    int a;
    while (cin >> a)
    {
        bool flag = true;
        if (a <= 0)
        {
            a = -a;
            flag = false;
        }

        int x = 1;
        int b = 0;
        while (a > 0)
        {
            b = b + (a % 8) * x;
            a = a / 8;
            x = x * 10;
        }
        if (flag)
            cout << b << endl;
        if (!flag)
            cout << -b << endl;
    }
}