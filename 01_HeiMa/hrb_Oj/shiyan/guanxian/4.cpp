#include "stdio.h"
#include "stdlib.h"
#define m 100
#define n 7
#define e 8
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
    }
}
void toposort(glinkheadnode g[])
{
    int i, v, w, sum = 0, indegree[n];
    struct
    {
        int s[n];
        int top;
    } stack;
    glinklistnode *p;
    for (i = 0; i < n; i++)
        indegree[i] = 0;
    for (i = 0; i < n; i++)
        for (p = g[i].firstarc; p != 0; p = p->nextarc)
            indegree[p->adjvertex]++;
    for (i = 0, stack.top = -1; i < n; i++)
        if (indegree[i] == 0)
        {
            stack.top++;
            stack.s[stack.top] = i;
        }
    while (stack.top != -1)
    {
        printf("%d\t", stack.s[stack.top]);
        sum = sum + 1;
        v = stack.s[stack.top];
        stack.top = stack.top - 1;
        p = g[v].firstarc;
        while (p != 0)
        {
            w = p->adjvertex;
            indegree[w] = indegree[w] - 1;
            if (indegree[w] == 0)
            {
                stack.top = stack.top + 1;
                stack.s[stack.top] = w;
            }
            p = p->nextarc;
        }
    }
    if (sum < n)
        printf("The AOV network has a cycle\n");
}
main()
{
    glinkheadnode g[m];
    createadjlist(g);
    toposort(g);
}