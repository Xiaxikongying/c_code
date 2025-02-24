#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2500
/*
3 2---->奶牛数量  防晒霜种类
3 10
2 5
1 5
6 2
4 1

2
*/

struct Data
{
    int a; //太阳强度L   或  防晒霜数量
    int b; //太阳强度H  或  防晒霜强度
};
Data cow[MAX + 5];
Data item[MAX + 5];

bool cmp(const Data &c1, const Data &c2)
{
    return c1.b < c2.b;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        cin >> cow[i].a >> cow[i].b;

    for (int i = 0; i < m; i++)
        cin >> item[i].b >> item[i].a;

    sort(cow, cow + n, cmp);    //根据最高承受强度升序
    sort(item, item + m, cmp); //根据强度升序

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (item[j].a > 0 && item[j].b >= cow[i].a && item[j].b <= cow[i].b)
            {
                ans += 1;
                item[j].a -= 1;
                break;
            }
        }
    }
    cout << ans << endl;

    // system("pause");
    return 0;
}
