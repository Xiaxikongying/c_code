#include <iostream>
using namespace std;
#define MAX 1000
//和成树
int val[MAX +5] = {0};  //每个节点的值
int fa[MAX +5] = {0};   //每个节点的父亲
int vis[MAX +5] = {0};  //是否被合并过
int size[MAX+5] = {0}; //每个节点内部有多少个节点（合并后增加）
double w[MAX+5] = {0}; //每个节点的价值  当两个节点合并后，价值为平均值，但值是两者之和
int n, r;
long long ans = 0;

int find_max() //找 w最大的点
{
    int x = -1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1 || i == r)//根节点和被合并的节点  不可合并
            continue;
        if (x == -1 || w[i] > w[x])
            x = i;
    }
    return x;
}

int find_fa(int x)
{
    if (vis[fa[x]])
        return find_fa(fa[x]);
    return fa[x];
}

int main()
{
    cin >> n >> r;//节点个数  根节点编号
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];  //1 - n  的权值
        fa[i] = i;
        size[i] = 1;
        w[i] = val[i];
        ans += val[i]; //合并到最后，root的值，这里先加上
    }

    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b; //父子关系
        fa[b] = a;
    }

    for (int i = 1; i < n; i++) // n个节点需要n-1次合并
    {
        //首先，需要找到最大值（的编号）将其合并给它的父亲
        int x = find_max();
        //然后找的它的父亲，与其合并
        int f = find_fa(x);
        ans += size[f] * val[x];
        vis[x] = 1;
        size[f] += size[x];
        val[f] += val[x];
        w[f] = 1.0 * val[f] / size[f];
    }

    cout << ans << endl;
    system("pause");
    return 0;
}
/*
第一行是节点个数  根节点编号
第二行是各个节点的权值 
后面子父子关系
5 1
1 2 1 2 4
1 2
1 3
2 4
3 5

33
*/