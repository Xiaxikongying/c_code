
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和 /或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/

// leetcode 200

class UnionSet
{
public:
    vector<int> fa;
    UnionSet(int n) : fa(n)
    {
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    int get(int x)
    {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }

    void merge(int a, int b)
    {
        fa[get(a)] = get(b);
        return;
    }
};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        UnionSet u(n * m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '0')
                    continue;
                int ind = m * i + j;
                
                if (j + 1 < m && grid[i][j + 1] == '1') //向右连通
                {
                    u.merge(ind, ind + 1);
                }

                if (i + 1 < n && grid[i + 1][j] == '1') //向下连通
                {
                    u.merge(ind, ind + m);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int ind = m * i + j;
                if (grid[i][j] == '1' && u.get(ind) == ind)
                    ans++;
            }
        }
        return ans;
    }
};

/*
入土
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int num = 0;
        int m = grid.size();
        int n = grid[0].size();
        int use[n * m];
        memset(use, 0, n * m*4);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == '0')
                    continue;

                num++;
                if (j + 1 < n && grid[i][j + 1] == '1') //与右边联通
                {
                    int ind = n * i + j + 1;
                    if (use[ind] == 0)
                    {
                        num--;
                        use[ind] = 1;
                    }
                }

                if (i + 1 < m && grid[i + 1][j] == '1') //与下联通
                {
                    int ind = n * (i + 1) + j;
                    if (use[ind] == 0)
                    {
                        num--;
                        use[ind] = 1;
                    }
                }
            }
        }
        return num;
    }
};
*/