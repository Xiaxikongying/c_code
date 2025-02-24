#include <iostream>
using namespace std;

/*
P1028 数的计算
给出正整数n，要求按如下方式构造数列:
1.只有一个数字 n 的数列是一个合法的数列。
2.在一个合法的数列的末尾加入一个正整数，但是这个正整数不能超过该数列最后一项的一半，可以得到个新的合法数列。
6
6
解释
6
6 1
6 2
6 3
6 2 1
6 3 1
*/
int f[1005] = {0};

int main()
{
    int n;
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i / 2; j >= 1; j--)
            f[i] += f[j];
        f[i] += 1;
    }
    cout << f[n] << endl;
    system("pause");
    return 0;
}
