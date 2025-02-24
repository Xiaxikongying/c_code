#include <iostream>
using namespace std;
#define MAX 10

int vis[MAX][MAX];
int Dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};
int n, m, ex, ey, num = 0;

void dfs(int x, int y)
{
    if (x == ex && y == ey)
    {
        num++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int dx = x + Dir[i][0];
        int dy = y + Dir[i][1];
        if (vis[dx][dy] == 1)
            continue;
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m)
        {
            vis[dx][dy] = 1;
            dfs(dx, dy);
            vis[dx][dy] = 0;
        }
    }
}

int main()
{
    int bx, by;
    int T, tx, ty;
    cin >> n >> m >> T;          //迷宫长度  障碍个数
    cin >> bx >> by >> ex >> ey; //起点  终点
    for (int i = 0; i < T; i++)
    {
        cin >> tx >> ty;
        vis[tx][ty] = 1;
    }
    vis[bx][by] = 1;
    dfs(bx, by);

    cout << num << endl;

    system("pause");
    return 0;
}
