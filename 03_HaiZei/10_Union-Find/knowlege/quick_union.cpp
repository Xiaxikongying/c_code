#include <iostream>
using namespace std;

#define MAX_N 10000
int fa[MAX_N + 5]; //表示第i个节点的父节点是什么

void init(int n)
{
    for (int i = 0; i <= n; i++)
        fa[i] = i;
    return;
}

int find(int x)//找父节点
{
    if (fa[x] == x)
        return x;
    return find(fa[x]);
}

int merge(int a, int b)
{
    int aa = find(a);
    int bb = find(b);
    if (aa == bb)
        return 0;
    fa[aa] = bb; //把a的父亲节点挂在b的父亲节点下面
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
}

int main()
{
    int n;
    cin >> n;
    init(n);
    int a, b;
    while (cin >> a >> b)
    {
        printf("merge %d with %d: %d\n", a, b, merge(a, b));
        output(n);
    }

    system("pause");
    return 0;
}