class Solution
{
public:
    vector<int> findOrder(int num, vector<vector<int>> &p)
    {
        vector<int> indegree(num, 0);
        vector<vector<int>> adList(num, vector<int>());

        //计算入度
        for (auto edge : p)
        {
            int a = edge[0];
            int b = edge[1];
            indegree[a]++;
            adList[b].push_back(a);
        }

        queue<int> q;
        //将度为0的点入队
        for (int i = 0; i < num; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            ans.push_back(f);

            int m = adList[f].size();
            for (int i = 0; i < m; i++)
            {
                int ind = adList[f][i];
                indegree[ind]--;
                if (indegree[ind] == 0)
                    q.push(ind);
            }
        }

        if (ans.size() == num)
            return ans;
        else
            return vector<int>();
    }
};