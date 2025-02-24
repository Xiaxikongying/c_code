#include <iostream>
using namespace std;

/*
​ 从 1−n这 n个整数中随机选取任意多个，每种方案里的数从小到大排列，按字典序输出所有可能的选择方案。
//  hai zei oj 235

样例输入
3
样例输出
1
1 2
1 2 3
1 3
2
2 3
3
*/

int arr[10];

void print_line(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i)
            cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return;
}
void meiju(int i, int j, int n) // i 指的是枚举数组中arr[i] ，j表示arr[i]的最小值，n表示最大选取的数字
{
    if (j > n)
        return;

    for (int k = j; k <= n; k++)
    {
        arr[i] = k;
        print_line(i);
        meiju(i + 1, k + 1, n);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    meiju(0, 1, n);
    system("pause");
    return 0;
}