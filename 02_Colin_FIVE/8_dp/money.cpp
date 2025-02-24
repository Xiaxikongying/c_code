#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int ans = 1e9;
int arr[3] = {1, 6, 11};
void dfs(int step, int now, int target)
{
    if (now > target || step >= ans)
        return;
    if (now == target)
    {
        if (step < ans)
            ans = step;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        int next = now + arr[i];
        dfs(step + 1, next, target);
    }
    return;
}

int vis[16] = {0};
void bfs(int step, int now, int target)
{
    queue<int> q;
    q.push(now);
    int size = 1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        int next;
        for (int i = 0; i < 3; i++)
        {
            next = f + arr[i];
            if (next > target)
                continue;
            if (next == target)
            {
                ans = step;
                return;
            }
            if (next < target && vis[next] == 0)
            {
                q.push(next);
                vis[next] = 1;
            }
        }
        size--;
        if (size == 0)
        {
            size = q.size();
            step++;
        }
    }
    return;
}

int main()
{
    bfs(1, 0, 15);
    //dfs(0, 0, 15);

    cout << ans << endl;
    system("pause");

    return 0;
}