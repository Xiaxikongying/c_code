#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
haizei oj 641
题目描述
给定一个有N个点，M条边的有向无权图，现求其拓扑排序。若有多个拓扑排序，则尽可能让小数在前大数在后
输入
输入文件第一行是两个整数n和接下来行,每行2个整数 b表示有一条a点到b点的边保证据中无环
输出
输出文件包含1 行，共有N 个整数，表示拓扑排序，每两个数中间用空格隔开

样例输入
7 6
1 2
1 4
2 3
4 5
3 6
5 6
样例输出
1 2 3 4 5 6 7
*/

#define MAX_N 2000
int indeg[MAX_N + 5] = {0};
vector<vector<int>> g(MAX_N + 5);
int ans[MAX_N + 5];
int cnt = 0;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        indeg[b]++;
        g[a].push_back(b);
    }
    set<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.insert(i);
    }
    while (q.size() > 0)
    {
        int now = *q.begin();
        ans[cnt++] = now;
        q.erase(q.begin());

        for (int i = 0, I = g[now].size(); i < I; i++)
        {
            int t = g[now][i];
            indeg[t]--;
            if (indeg[t] == 0)
                q.insert(t);
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        if(i)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;

    system("pause");
    return 0;
}