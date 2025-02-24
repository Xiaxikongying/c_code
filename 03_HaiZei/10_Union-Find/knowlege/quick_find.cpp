#include <iostream>
using namespace std;

#define MAX_N 10000
int color[MAX_N + 5];

void init(int n)
{
    for (int i = 0; i <= n; i++)
        color[i] = i;
    return;
}

int find(int a)
{
    return color[a];
}
int merge(int a, int b, int n)
{
    int aa = find(a);
    int bb = find(b);
    if (aa == bb)
        return 0;
    for (int i = 0; i <= n; i++)
    {
        if (color[i] == aa)
            color[i] = bb;
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
        printf("%3d", color[i]);
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
        printf("merge %d with %d result:%d\n", a, b, merge(a, b, n));
        output(n);
    }

    system("pause");
    return 0;
}