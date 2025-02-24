#include "stdio.h"
#define m 100
#include "stdlib.h"
#define n 6
#define e 6
int visited[m];
typedef struct node1
{
    int info;
    int adjvertex;
    struct node1 *nextarc;
} glinklistnode;
typedef struct node2
{
    int vertexinfo;
    glinklistnode *firstarc;
} glinkheadnode;
void createadjlist(glinkheadnode g[])
{
    int i, j, k;
    glinklistnode *p;
    for (i = 0; i < n; i++)
    {
        g[i].vertexinfo = i;
        g[i].firstarc = 0;
    }
    for (k = 0; k < e; k++)
    {
        scanf("%d,%d", &i, &j);
        p = (glinklistnode *)malloc(sizeof(glinklistnode));
        p->adjvertex = j;
        p->nextarc = g[i].firstarc;
        g[i].firstarc = p;
        p = (glinklistnode *)malloc(sizeof(glinklistnode));
        p->adjvertex = i;
        p->nextarc = g[j].firstarc;
        g[j].firstarc = p;
    }
}
void dfs(glinkheadnode g[], int v0)
{
    glinklistnode *p;
    printf("%d\t", v0);
    visited[v0] = 1;
    p = g[v0].firstarc;
    while (p != 0)
    {
        if (visited[p->adjvertex] == 0)
            dfs(g, p->adjvertex);
        p = p->nextarc;
    }
}
main()
{
    glinkheadnode g[m];
    createadjlist(g);
    dfs(g, 0);
}