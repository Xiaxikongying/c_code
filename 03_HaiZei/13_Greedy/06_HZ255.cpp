#include <iostream>
#include <cmath>
#include <map>
using namespace std;

//雷达探测
/*
3 2
1 2
-3 1
2 1

2
*/
int main()
{
    int n;
    double r;
    multimap<double, double> m;

    cin >> n;
    cin >> r;
    double x, y, L, R;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (y > r)
        {
            cout << -1 << endl;
            return 0;
        }
        L = x - sqrt(r * r - y * y);
        R = x + sqrt(r * r - y * y);
        m.insert(make_pair(R, L));
    }

    int cnt = 1;
    multimap<double, double>::iterator ite = m.begin();
    R = (*ite).first;
    ite++;
    while (ite != m.end())
    {
        if ((*ite).second > R)
        {
            cnt++;
            R = (*ite).first;
        }
        ite++;
    }
    cout << cnt << endl;

    system("pause");
    return 0;
}

/*

struct Range
{
    double l, r;
} arr[MAX_N + 5];

bool cmp(const Range &a, const Range &b)
{
    return a.r < b.r;
}

int main()
{
    int n;
    double r, x, y, pos;
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (y > r)
        {
            cout << -1 << endl;
            return 0;
        }
        double delta = sqrt(r * r - y * y);
        arr[i].l = x - delta;
        arr[i].r = x + delta;
    }
    sort(arr, arr + n, cmp);
    int ans = 1;
    pos = arr[0].r;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].l > pos)
        {
            ans += 1;
            pos = arr[i].r;
        }
    }
    cout << ans << endl;
    return 0;
}
* /
