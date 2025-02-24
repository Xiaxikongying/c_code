#include <iostream>
using namespace std;
#include <queue>
/*
P1135 奇怪的电梯
输入格式
第一行为三个用空格隔开的正整数，表示 N,A,B(1 < N < 200，1 < A,B < N)
    （N表示有多少层楼   A表示起点   B表示终点）
第二行为 N个用空格隔开的非负整数，表示K。
    （每个数字表示当前楼层可以向上（下）移动的层数）

输出格式
一行，即最少按键次数，若无法到达，则输出 -1 。

1< N < 200，1 < A,B < N，< Ki N
*/
#define MAX 200

int to[MAX + 5];  //每层的可移动的步数
int dis[MAX + 5]; // A到每个点的距离  若为n则表示不可达

void dfs(int step, int a, int n) // step表示步数  a表示当前楼层  n总楼层数
{
    if (step >= dis[a]) //剪去较长的路径
        return;
    dis[a] = step;

    if (a + to[a] <= n)
        dfs(step + 1, a + to[a], n);
    if (a - to[a] >= 1)
        dfs(step + 1, a - to[a], n);
    return;
}

int bfs(int a, int b, int n)
{
    queue<int> q;
    q.push(a);
    dis[a] = 0;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (f == b)
            return dis[b];

        int ind1 = f + to[f];
        int ind2 = f - to[f];

        if (ind1 <= n && dis[ind1] == n)
        {
            q.push(ind1);
            dis[ind1] = dis[f] + 1;
        }
        if (ind2 >= 1 && dis[ind2] == n)
        {
            q.push(ind2);
            dis[ind2] = dis[f] + 1;
        }
    }
    return -1;
}
/*
5 1 5
3 3 1 2 5
*/
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    //输入每层的K
    for (int i = 1; i <= n; i++)
    {
        cin >> to[i];
        dis[i] = n; //最多的操作步数为n-1  ， n则是最大值
    }

    /*
    dfs(0, a, n);
    if (dis[b] != n)
        cout << dis[b] << endl;
    else
        cout << -1 << endl;
    */
   
    cout << bfs(a, b, n) << endl;
    system("pause");
    return 0;
}
