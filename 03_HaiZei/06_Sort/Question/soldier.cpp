#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
些土兵站在阵的一些方格内，现要把他们移动到排，并连续地排成一队，兵一次可以选择四方向中的一个方向移动一，
求最少需要移动多少步才能完或要求即所有士兵的y坐标相同并且x坐标相邻。

输入
第一行输入一个正整数n，表示士兵的数量。 (1  n s 10000)
接下来n行，每行两个数，代表第 个士兵所处位置的横纵坐标 Xi,Yi。 ( - 10000 < xi, yi  10000)输出
输出最少移动步数。

样例输入
5
1 2
2 2
1 3
3 -2
3 3
样例输出
8
//haizei oj 251
*/
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int X, Y, constX = 0, constY = 0;

    sort(y.begin(), y.end());
    Y = y[n / 2];
    for (int i = 0; i < n; i++)
        constY += abs(y[i] - Y);


    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++)
        x[i] -= i;
        
    
    sort(x.begin(), x.end());
    X = x[n / 2];
    for (int i = 0; i < n; i++)
        constX += abs(x[i]-X);

        cout << constX + constY << endl;
    system("pause");
    return 0;
}