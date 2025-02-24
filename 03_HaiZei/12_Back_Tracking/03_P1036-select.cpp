#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int arr[20];
int temp[20];
int ans = 0;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) // 如果不为素数返回0
            return false;
    }
    return true; // 反之则返回1
}

// a表示当前已经选取了a个数字  ind表示选取的数字下标最小应该是ind，
// n表示一共有n个数字待选   k表示一共要选择k个数
void dfs(int a, int ind, int n, int k)
{
    if (a == k)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += temp[i];
        if (isPrime(sum))
            ans++;
        return;
    }

    for (int i = ind; i < n; i++) //从arr[ind] 到 arr[n-1]中选取1个数字
    {
        temp[a] = arr[i];
        dfs(a + 1, i + 1, n, k);
    }
}
/*
4 3
3 7 12 19
1
*/
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dfs(0, 0, n, k);
    cout << ans << endl;
    system("pause");
    return 0;
}
