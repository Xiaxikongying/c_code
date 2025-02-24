#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// haizei oj636
/*
样例输入
5 6
1 2
1 3
2 3
2 4
3 4
2 5
样例输出
1
2
3
4
3
*/

#define MAX_N 100000
int indeg[MAX_N + 5] = {0};
int ans[MAX_N + 5] = {0}; //表示到达当前城市最多能游览多少个城市。
vector<vector<int>> g(MAX_N);

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        indeg[y]++;
        g[x].push_back(y);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0, I = g[now].size(); i < I; i++)
        {
            int t = g[now][i];
            indeg[t]--;
            if (indeg[t] == 0)
                q.push(t);
            ans[t] = ans[now] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", ans[i]);
    }

    system("pause");
    return 0;
}