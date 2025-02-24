#include "stdio.h"
#define max 32767
#define n 6
void prim(int matrix[n][n], int v0)
{
    int i, j, k, min, lowcost[n], closet[n];
    for (i = 0; i <= n - 1; i++)
        if (i != v0)
        {
            lowcost[i] = matrix[v0][i];
            closet[i] = v0;
        }
        else
            lowcost[i] = 0;
    for (i = 1; i <= n - 1; i++)
    {
        for (min = max, j = 0; j <= n - 1; j++)
            if (min > lowcost[j] && lowcost[j] != 0)
            {
                min = lowcost[j];
                k = j;
            }
        printf("%d->%d:%d\n", k, closet[k], min);
        lowcost[k] = 0;
        for (j = 0; j <= n - 1; j++)
            if (matrix[k][j] < lowcost[j] && lowcost[j] != 0)
            {
                lowcost[j] = matrix[k][j];
                closet[j] = k;
            }
    }
}
main()
{
    int matrix[n][n] = {{max, 6, 1, 5, max, max}, {6, max, 5, max, 3, max}, {1, 5, max, max, 6, 4}, {5, max, max, max, max, 2}, {max, 3, 6, max, max, 6}, {max, max, 4, 2, 6, max}};
    prim(matrix, 5);
}