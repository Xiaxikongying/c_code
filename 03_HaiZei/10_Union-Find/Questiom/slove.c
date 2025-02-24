/*
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

leetcode 130
*/

class UnionSet
{
public:
    vector<int> fa;
    UnionSet(int n) : fa(n + 1)
    {
        for (int i = 0; i <= n; i++)
            fa[i] = i;
    }
    int get(int x)
    {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }

    void merge(int a, int b)
    {
        if (get(a) == get(b))
            return;
        fa[get(a)] = get(b);
        return;
    }
};

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        UnionSet u(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //下标从1开始  下标0给到最外圈
                int ind = i * n + j + 1;
                if (board[i][j] != 'O')
                    continue;
                else
                {
                    if (i == 0 || i == m - 1)
                        u.merge(ind, 0);
                    if (j == 0 || j == n - 1)
                        u.merge(ind, 0);

                    //与右边的点联通
                    if (j + 1 < n && board[i][j + 1] == 'O')
                        u.merge(ind, ind + 1);
                    //与下面的点联通
                    if (i + 1 < m && board[i + 1][j] == 'O')
                        u.merge(ind, ind + n);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != 'O')
                    continue;
                else
                {
                    int ind = i * n + j + 1;
                    if (u.get(ind) != u.get(0))
                        board[i][j] = 'X';
                }
            }
        }
        return;
    }
};