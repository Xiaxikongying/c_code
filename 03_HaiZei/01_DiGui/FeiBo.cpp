#include <iostream>
using namespace std;

int f(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return f(n - 1) + f(n - 2);
}

int main()
{
    cout << f(7) << endl;
    system("pause");
    return 0;
}