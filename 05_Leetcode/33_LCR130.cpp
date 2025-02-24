class Solution
{
public:
    int sums(int x)
    {
        int s = 0;
        while (x != 0)
        {
            s += x % 10;
            x = x / 10;
        }
        return s;
    }

    int dfs(int i, int j, vector<vector<int>> &vis, int m, int n, int cnt)
    {
        if (i >= m || j >= n || sum(i) + sum(j) > cnt || vis[i][j])
            return 0;

        return 1 + dfs(i + 1, j, vis, m, n, cnt) + dfs(i, j + 1, vis, m, n, cnt);
    }

    int wardrobeFinishing(int m, int n, int cnt)
    {
        vector<vector<int>> vec(m, vector<int>(n, 0));
        return dfs(0, 0, vis, m, n, cnt);
    }
};