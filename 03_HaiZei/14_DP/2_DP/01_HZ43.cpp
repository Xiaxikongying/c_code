#include <iostream>
#include <algorithm>
using namespace std;

int f[1005][1005] = {0};
int w[1005][1005] = {0};
//数字三角形
/*
6
3
9 5
4 2 1
3 4 9 6
3 5 3 7 3
2 1 3 9 3 2

39
*/
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> f[i][j];
            w[i][j] = f[i][j];
            if (i >= 2)
                w[i][j] += max(w[i - 1][j], w[i - 1][j - 1]);
        }
    }


    int m = w[n][1];
    for (int i = 2; i <= n; i++)
    {
        if (m < w[n][i])
            m = w[n][i];
    }
    cout << m << endl;
    system("pause");
    return 0;
}

