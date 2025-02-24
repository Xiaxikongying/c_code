#include <iostream>
#include <math.h>
using namespace std;
// 汉诺塔
void hannuo(int n, string a, string b, string c)
{
    if (n == 1)
    {
        cout << a << " 移动到 " << c << endl; // 若只有一个，直接从a移动到c
    }
    else
    {
        hannuo(n - 1, a, c, b);               // 若有n个 先把n-1个块从a借助c移动到b
        cout << a << " 移动到 " << c << endl; // 再把最大的块从a移动到c
        hannuo(n - 1, b, a, c);               // 再把n-1个块从b 借助a 移动到c
    }
}

int hannuo(int n)
{
    return pow(2, n) - 1;
}

int main()
{
    hannuo(3, "塔1", "塔2", "塔3");
    cout << hannuo(5) << endl;
    system("pause");
    return 0;
}