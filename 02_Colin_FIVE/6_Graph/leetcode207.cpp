class Solution
{
public:
    bool canFinish(int num, vector<vector<int>> &p)
    {
        vector<int> indegree(num, 0);
        vector<vector<int>> addList(num, vector<int>());

        //计算入度
        /*
        edge ::= [1,0]  [2,0] [3,1]--->  表示学1前必须先学0
        */
        for (auto edge : p)
        {
            int a = edge[0];
            int b = edge[1];
            indegree[a]++;
            addList[b].push_back(a);  //0号存储 1 2 表示学了0，度1 2 都需要减1
        }

        queue<int> q;
        for (int i = 0; i < num; i++)
        {
            if (indegree[i] == 0) //入度为0的顶点入队
                q.push(i);
        }

        int count = 0;
        //用来计数 若所学课程count 与 总课程 num相同，则表示可以完成课程表
        while (!q.empty())
        {
            int f = q.front();//f接收度为0的顶点
            q.pop();
            count++;

            int m = addList[f].size();
            //度为0的顶点，学习后 将需要这门课的课程-1
            for (int i = 0; i < m; i++)
            {
                int ind = addList[f][i];
                indegree[ind]--;
                if (indegree[ind] == 0)
                    q.push(ind);
            }
        }

        return (count == num);
    }
};