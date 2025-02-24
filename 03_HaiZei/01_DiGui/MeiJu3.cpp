#include <iostream>
using namespace std;

//  hai zei oj 237
/*
3
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
int arr[10], vis[10] = {0};
// vis[i] = 0 表示数字i未被使用

void print_line(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return;
}

void MeiJu(int i, int n)
{
    if (i == n)
    {
        print_line(n);
        return;
    }

    for (int k = 1; k <= n; k++)
    {
        if (vis[k] == 1)
            continue;
        arr[i] = k;
        vis[k] = 1;
        MeiJu(i + 1, n);
        vis[k] = 0;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    MeiJu(0, n);
    system("pause");
    return 0;
}