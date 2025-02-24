#include <iostream>
using namespace std;

/*
P1044 栈的输出方法
3 
5
解释
1 2 3
2 1 3
1 3 2
2 3 1
3 2 1

以 x 为结尾的方法数为   f[x-1] * f[n-x]
比x小的数字必须先在 X入栈前面 入栈出栈  符合要求的元素个数有x-1个----> f[x-1]
比x大的数字 必须在x入栈后 入栈出栈      符合要求的元素个数有n-x个---->f[n-x]
x再在最后出栈
*/
int f[20] = {0};

int main()
{
    f[0] = 1;
    f[1] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
            f[i] += f[j - 1] * f[i - j];
    }

    cout << f[n] << endl;
    system("pause");
    return 0;
}
