#include <iostream>
#include <queue>
using namespace std;
#define MAX 400

int dis[MAX][MAX]; //表示到棋盘中每个点的距离
int Dir[8][2] = {
    {2, 1},
    {-2, 1},
    {2, -1},
    {-2, -1},
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2}};
int n, m;

void dfs(int step, int x, int y)
{
    if (dis[x][y] != -1 && step >= dis[x][y])
        return;
    dis[x][y] = step;
    for (int i = 0; i < 8; i++)
    {
        int dx = x + Dir[i][0];
        int dy = y + Dir[i][1];
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m)
        {
            dfs(step + 1, dx, dy);
        }
    }
}
typedef struct Node
{
    int x, y, step;
    Node(int x, int y, int s) : x(x), y(y), step(s) {}
} Node;

void bfs(int x, int y)
{
    queue<Node> q;
    int step;
    q.push(Node(x, y, 0));
    dis[x][y] = 0;

    while (!q.empty())
    {
        x = q.front().x;
        y = q.front().y;
        step = q.front().step;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int dx = x + Dir[i][0];
            int dy = y + Dir[i][1];

            if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && dis[dx][dy] == -1)
            {
                dis[dx][dy] = step + 1;
                q.push(Node(dx, dy, step + 1));
            }
        }
    }
}

int main()
{
    int x, y;
    cin >> n >> m >> x >> y;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            dis[i][j] = -1;

    // dfs(0, x, y);
    bfs(x, y);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << dis[i][j] << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}
