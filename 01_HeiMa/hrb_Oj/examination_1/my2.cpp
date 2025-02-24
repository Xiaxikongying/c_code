#include <iostream>
using namespace std;

void zhuanzhi()
{
    int n;
    cin >> n;
    int arr[n][n];
    int arr1[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr1[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1 ; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout <<arr1[i][n-1]<< endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        zhuanzhi();
    }
    system("pause");
    return 0;
}

/*
B.矩阵转置


写一个函数，实现矩阵的转置，即行列互换。为了简化问题，只是实现N x N 矩阵的转置。

Input
给定一个整数T，代表T组测试数据。
对于每组测试数据，第一行是一个整数N(N<=10)，含义如上所述。
接下来N行是一个N x N的矩阵。

Output
对于每组测试数据，输出转置后的矩阵，见样例。


Sample Input
1
3
1 2 3
4 5 6
7 8 9


Sample Output
1 4 7
2 5 8
3 6 9

*/