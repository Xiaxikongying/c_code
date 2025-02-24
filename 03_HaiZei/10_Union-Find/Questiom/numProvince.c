/*
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
返回矩阵中 省份 的数量。

leetcode 547
*/

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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        UnionSet u(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                    u.merge(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (u.get(i) == i)
                ans++;
        }
        return ans;
    }
};