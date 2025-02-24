#include <iostream>
using namespace std;
#define MAX 100
int arr[MAX + 3][MAX + 3];
/*
最大子阵和
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

15
*/
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j];
        }
    }

    int s = 0;
    int ans = -1000000000;
    int a = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            s = 0;
            for (int k = 1; k <= n; k++)
            {
                a = arr[j][k] - arr[i - 1][k]; //得到这一列的和
                if (s >= 0) //若当前的和值大于0 则继续向后探索
                    s += a;
                else        //若和值小于0  则放弃该列，从下一列开始
                    s = a;
                if (s > ans)
                    ans = s;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}