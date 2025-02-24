#include <iostream>
using namespace std;
#define MAX 8
int n;
int arr[MAX + 2];

void output(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << arr[i] << "+";
    cout << arr[n - 1] << endl;
}

void dfs(int sum, int cnt, int pre) // sum 相加的总值  cnt现在在选择下标为cnt的数字  pre上一次选择的数字
{
    if (sum == n)
    {
        output(cnt);
        return;
    }

    for (int i = pre; i < n; i++) //永远选择不小于上一次选择的数字
    {
        if (sum + i <= n)
        {
            arr[cnt] = i;
            dfs(sum + i, cnt + 1, i);
        }
    }
}

int main()
{
    cin >> n;
    dfs(0, 0, 1);
    system("pause");
    return 0;
}
