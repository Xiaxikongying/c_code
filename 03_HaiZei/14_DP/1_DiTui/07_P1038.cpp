#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
P1038  这个题目应该归类为拓扑排序  而不是DP
5 6
1 0
1 0
0 1
0 1
0 1
1 3 1
1 4 1
1 5 1
2 3 1
2 4 1
2 5 1

3 1
4 1
5 1
*/
int c[1005], u[1005];     //状态
int w[1005][1005];        //权值
int indeg[1005];          //入度
vector<int> outdeg[1005]; //出度
/*
c[i] = w[j][i] * c[j] - u[i]  //j是与i连接的所有点
c[j] 必须大于0才计入计算
*/
int main()
{
    int n, p; //点的数量，边的数量
    cin >> n >> p;

    for (int i = 1; i <= n; i++) //给点附上状态
    {
        cin >> c[i] >> u[i];
        if (c[i] == 0)
            c[i] = -u[i]; //计算输出点时 最后要-u[i],这里直接提前减掉
    }
    for (int i = 0, a, b, d; i < p; i++)
    {
        cin >> a >> b >> d; //表示从a到b的边权值为d
        w[a][b] = d;
        outdeg[a].push_back(b);
        indeg[b] += 1;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int ind = q.front();
        q.pop();
        for (int i = 0; i < outdeg[ind].size(); i++)
        {
            int to = outdeg[ind][i];
            indeg[to]--;

            if (c[ind] > 0)
                c[to] += w[ind][to] * c[ind];
            if (indeg[to] == 0)
                q.push(to);
        }
    }

    int flag = 1;
    for (int i = 0; i <= n; i++)
    {
        if (!outdeg[i].empty() || c[i] <= 0)
            continue;
        cout << i << " " << c[i] << endl;
        flag = 0;
    }

    if (flag)
        cout << "NULL" << endl;
    system("pause");
    return 0;
}
/*
6 8
1 0
1 0
1 100
0 1
0 -2
0 0

1 4 1
2 4 0
3 4 -1
1 5 1
2 5 -1
3 5 -1
4 6 1
5 6 1

输出
6 1
*/