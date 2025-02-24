#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
/*
1 2
100 3
100 2
100 1

1 50004
*/

struct Data
{
    int a; //时间
    int b; //强度
};
Data machine[MAX + 5];
Data work[MAX + 5];

bool cmp(const Data &c1, const Data &c2)
{
    if (c1.a != c2.a)
        return c1.a > c2.a;
    return c1.b > c2.b;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &machine[i].a, &machine[i].b);

    for (int i = 0; i < m; i++)
        scanf("%d %d", &work[i].a, &work[i].b);

    sort(machine, machine + n, cmp); //工作时间长，难度高的放前面
    sort(work, work + m, cmp); //将时间长  难度系数高的任务放在前面

    long long ans = 0;
    int cnt = 0;
    vector<int> hard(101, 0);

    for (int i = 0, j = 0; i < m; i++) //遍历每一个任务
    {
        while (j < n && machine[j].a >= work[i].a) //查看该任务有多少机器 在时间上  可以完成
        {
            hard[machine[j].b] += 1;
            j += 1;
        }
        for (int k = work[i].b; k <= 100; k++) //在时间要求达标的机器中 选择一个最难度最低的
        {
            if (hard[k] == 0)
                continue;
            hard[k]--;
            cnt++;
            ans += (work[i].a * 500 + work[i].b * 2);
            break;
        }
    }

    cout << cnt << " " << ans << endl;

    system("pause");
    return 0;
}
