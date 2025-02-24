#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_Test.h"

/*
1、设计⼀个【步长】序列
2、按照步长，对序列进⾏分组，每组采用插⼊排序
3、直到执⾏到步长为1为⽌
*/



void insert_sort(int *arr, int l, int r, int step)
{
    for (int i = l + step; i < r; i += step)
    {
        int j = i;
        while (arr[j] < arr[j - step] && j > l)
        {
            swap(arr[j], arr[j - step]);
            j -= step;
        }
    }
}

void shell_sort(int *arr, int l,int r)
{
    int k = 2;
    int n = r;
    int step;
    do
    {
        step = n / k == 0 ? 1 : n / k;
        for (int i = 0; i < step; i++)
            insert_sort(arr, i, r, step);

        k *= 2;
    } while (step != 1);
}

void shell_sort_hibbard(int *arr, int l,int r)
{
    int step = 1;
    int n = r;
    while (step <= n / 2)
        step = step * 2 + 1;

    do
    {
        step /= 2;
        for (int i = 0; i < step; i++)
            insert_sort(arr, i, r, step);
    } while (step > 1);
    return;
}

int main()
{
    int *arr = getRandData(BIG_DATA_N);
    TEST(shell_sort, arr, BIG_DATA_N);
    TEST(shell_sort_hibbard, arr, BIG_DATA_N);
    free(arr);

    system("pause");
    return 0;
}