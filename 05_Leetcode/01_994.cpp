struct Node
{
    int x, y, s;
    Node(int x, int y, int s) : x(x), y(y), s(s) {}
};

class Solution
{
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> arr(m + 2, vector<int>(n + 2, -1));
        queue<Node> q;
        int cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = grid[i - 1][j - 1];
                if (arr[i][j] == 2)
                    q.push(Node(i, j, 0));
                if (arr[i][j] == 1)
                    cnt++;
            }
        }
        int x, y, ds, dx, dy;
        while (!q.empty())
        {
            x = q.front().x;
            y = q.front().y;
            ds = q.front().s;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                dx = x + dir[i][0];
                dy = y + dir[i][1];
                if (arr[dx][dy] == 1)
                {
                    q.push(Node(dx, dy, ds + 1));
                    arr[dx][dy] = 2;
                    cnt--;
                }
            }
            if (cnt == 0)
                return ds + 1;
        }
        return -1;
    }
};