#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个方向数组用于上下左右的移动
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// 计算某个位置的宝物值
int getTreasure(int i, int j, int m)
{
    return j + i * m;
}

// BFS 方法，计算在给定步数内游游最多可以收集的宝物
int bfs(int n, int m, int k)
{
    // BFS 需要一个队列，队列中的元素是 {i, j, 步数, 当前宝物总和}
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, getTreasure(0, 0, m)}});
    int maxTreasure = getTreasure(0, 0, m);

    // 记录访问过的格子，避免重复访问
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;

    // BFS 执行
    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int x = current.first.first;
        int y = current.first.second;
        int steps = current.second.first;
        int totalTreasure = current.second.second;

        // 如果走的步数超过 k，停止搜索
        if (steps >= k)
        {
            continue;
        }

        // 遍历四个方向
        for (int d = 0; d < 4; ++d)
        {
            int newX = x + dir[d][0];
            int newY = y + dir[d][1];

            // 确保新的位置在矩阵范围内
            if (newX >= 0 && newX < n && newY >= 0 && newY < m)
            {
                // 计算该位置的宝物值
                int newTreasure = getTreasure(newX, newY, m);
                int newTotalTreasure = totalTreasure + newTreasure;

                // 更新最大宝物值
                maxTreasure = max(maxTreasure, newTotalTreasure);

                // 将新的位置加入队列并标记为访问
                q.push({{newX, newY}, {steps + 1, newTotalTreasure}});
            }
        }
    }

    return maxTreasure;
}

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        cout << bfs(n, m, k) << endl;
    }
    system("pause");
    return 0;
}