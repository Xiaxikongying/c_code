#include <iostream>
using namespace std;
//按秩优化
#define MAX_N 10000
int fa[MAX_N + 5];   //表示第i个节点的父节点是什么
int size[MAX_N + 5]; //节点数量
void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        fa[i] = i;
        size[i] = 1;
    }

    return;
}

int find(int x) //找父节点
{
    return fa[x] = (fa[x] == x ? x : find(fa[x]));
    //判断fa[x]是不是根节点  若不是，则返回父节点
    //并且把fa[x]挂在find(fa[x])上，也就是挂在父节点上
}

int merge(int a, int b)
{
    int aa = find(a);
    int bb = find(b);
    if (aa == bb)
        return 0;
    if (size[aa] < size[bb]) //谁节点多就当父节点
    {
        fa[aa] = bb;
        size[bb] += size[aa];
    }
    else
    {
        fa[bb] = aa;
        size[aa] += size[bb];
    }

    return 1;
}

void output(int n)
{
    int len = 0;
    for (int i = 0; i <= n; i++)
    {
        len += printf("%3d", i);
    }

    printf("\n");
    for (int i = 0; i <= len; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i <= n; i++)
    {
        printf("%3d", fa[i]);
    }
    printf("\n");

    for (int i = 0; i <= n; i++)
    {
        printf("%3d", size[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    cin >> n;
    init(n);
    int a, b;
    while (cin >> a >> b)
    {
        if (a == -1)
            break;
        printf("merge %d with %d: %d\n", a, b, merge(a, b));
        output(n);
    }

    system("pause");
    return 0;
}