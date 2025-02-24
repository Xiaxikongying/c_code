#include <iostream>
using namespace std;
/*
题目描述
​ 从 1 - n 这 n 个整数中随机选取 m个，每种方案里的数从小到大排列，按字典序输出所有可能的选择方案。
 输入输入两个整数 n,m。（1≤m≤n≤10）（1≤n≤m≤10）
 输出每行一组方案，每组方案中两个数之间用空格分隔。 ​ 注意每行最后一个数后没有空格。
3 2
 1 2
 1 3
  2 3
*/
//  hai zei oj 236
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

void MeiJu(int i, int j, int n, int m)
{
    if (i == m) //当MeiJu(i=m) 进入时，arr[i]此时还没有赋值,
    {           //  而arr[0] 到 arr[m-1]已经有m个值了
        print_line(m - 1);
        return;
    }

    for (int k = j; k <= n && n - k >= m - i - 1; k++)
    {
        arr[i] = k;
        MeiJu(i + 1, k + 1, n, m);
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    MeiJu(0, 1, n, m);
    system("pause");
    return 0;
}