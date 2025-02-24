#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
int dist[N]; // 存储起始点到各个节点的最短距离
bool st[N];  // 标记节点是否已经确定最短距离
int n, m;    // 节点数和边数
int g[N][N]; // 图的邻接矩阵

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist)); // 初始化起始点到所有节点的距离为无穷大
    for (int i = 0; i < N; i++)
    {
        st[i] = false; // 初始化标记数组
    }
    dist[1] = 0; // 起始点到自身的距离为0
    int k = n;
    while (k--)
    {
        int t = -1; // 存储当前最短距离的节点
        for (int i = 1; i <= n; i++)
        {
            if (st[i] == false && (t == -1 || dist[t] > dist[i]))
            {
                t = i;
            }
        }
        st[t] = true; // 将最短距离的节点标记为已确定最短距离
        for (int i = 1; i <= n; i++)
        {
            if (st[i] == false)
            {
                dist[i] = min(dist[i], dist[t] + g[t][i]);
                // 更新起始点到其他节点的最短距离
            }
        }
    }
}
int main()
{
    while (cin >> n >> m)
    {
        memset(g, 0x3f, sizeof(g)); // 初始化图的邻接矩阵为无穷大
        for (int i = 1; i <= n; i++)
        {
            st[i] == false; // 初始化标记数组
        }
        while (m--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g[x][y] = z; // 设置节点x和节点y之间的边权值为z
            g[y][x] = z; // 由于是无向图，所以边是双向的，需要同时设置两个方向的边权值
        }
        dijkstra(); // 调用dijkstra算法求解最短路径
        if (dist[n] == 0x3f)
        {
            cout << "-1" << endl; // 如果起始点无法到达终点n，则输出-1
        }
        else
        {
            cout << dist[n] << endl; // 输出起始点到终点n的最短距离
        }
    }
    system("pause");
    return 0;
}
