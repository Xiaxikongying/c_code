#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef struct Graph
{
    int Vnum; //顶点个数
    int Enum; //边条数
    int *arr;
} Graph;

Graph *getnewGraph(int Vnum)
{
    Graph *p = (Graph *)malloc(sizeof(Graph));
    p->Vnum = Vnum;
    p->Enum = 0;
    p->arr = (int *)malloc(sizeof(int) * Vnum * Vnum);
    memset(p->arr, 0, (sizeof(int) * Vnum * Vnum));
    return p;
}

void insert_Edge(Graph **g, int head, int tail)
{
    if (head > (*g)->Vnum || tail > (*g)->Vnum || head == tail)
    {
        cout << "输入数据有误" << endl;
        return;
    }
    int index1 = (head - 1) * (*g)->Vnum + (tail - 1);
    int index2 = (tail - 1) * (*g)->Vnum + (head - 1);
    (*g)->arr[index1] = 1;
    (*g)->arr[index2] = 1;
    (*g)->Enum++;
}

void output(Graph *g)
{
    cout << "该图有" << g->Vnum << "个顶点" << endl;
    cout << "该图有" << g->Enum << "条边" << endl;
    int index;
    for (int i = 0; i < g->Vnum; i++)
    {
        for (int j = 0; j < g->Vnum; j++)
        {
            index = i * g->Vnum + j;
            cout << g->arr[index] << " ";
        }
        cout << endl;
    }
}

int vis[100] = {0};
void dfs(Graph *g, int s) // s是起始点
{
    printf("%d ", s);
    int start = (s - 1) * g->Vnum;
    int end = start + 5;
    vis[s] = 1;
    for (int i = start; i < end; i++)
    {
        if (vis[i - start + 1] == 1) // i - start 从0开始 所以要加上1 来检测第一个顶点
            continue;
        if (g->arr[i] != 0)
        {
            s = i - start + 1;
            dfs(g, s);
        }
    }
}


void bfs(Graph *g, int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    int start, end;
    while (!q.empty())
    {
        s = q.front(); //更换顶点
        start = (s - 1) * g->Vnum;
        end = start + 5;
        for (int i = start; i < end; i++)
        {
            if (vis[i - start + 1] == 0 && g->arr[i] != 0)
            {
                s = i - start + 1;
                q.push(s);
                vis[s] = 1;
            }
        }
        printf("%d ", q.front());
        q.pop();
    }
}
// 6
// 1 2 1 3 1 4 2 3 3 4 4 5
int main()
{
    Graph *g = getnewGraph(5);
    int a, b;
    int count;
    cout << "请输入你要插入边的条数: ";
    cin >> count;
    cout << endl;

    while (count--)
    {
        cin >> a >> b;
        insert_Edge(&g, a, b);
    }
    output(g);

    cout << endl<<"DFS:";
    dfs(g, 2);
    cout << endl;

    memset(vis, 0, sizeof(int) * 100);
    cout << endl<<"BFS:";
    bfs(g, 2);
    cout << endl;

    system("pause");
    return 0;
}