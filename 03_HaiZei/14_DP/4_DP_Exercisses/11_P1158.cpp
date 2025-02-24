#include <iostream>
#include <algorithm>
using namespace std;
/*
导弹拦截
*/
#define POW(x) ((x) * (x))
#define S(a, b) (POW(a) + POW(b))
struct Data
{
    int d1, d2;
} arr[100005];

bool cmp(Data &a, Data &b)
{
    return a.d1 < b.d1;
}

int main()
{
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for (int i = 0, a, b; i < n; i++)
    {
        cin >> a >> b;
        arr[i].d1 = S((a - x1), (b - y1));
        arr[i].d2 = S((a - x2), (b - y2));
    }
    sort(arr, arr + n, cmp);

    int r2 = 0;
    int ans = arr[n - 1].d1;         // 全部给1拦截
    for (int i = n - 1; i >= 0; i--) // 将[i ~ n-1]的导弹给2拦截
    {
        if (r2 < arr[i].d2)
            r2 = arr[i].d2;
        ans = min(ans, arr[i - 1].d1 + r2);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
