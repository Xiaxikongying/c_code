#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_Test.h"

/*
1、将数组分成『已排序区』和『待排序区』
2、每⼀轮从『待排序区』中选择⼀个最小的元素放到『已排序区』的尾部
3、直到『待排序区』没有元素为⽌
*/

void selection_sort(int *arr, int l, int r)
{
    for (int i = l; i < r - 1; i++)
    {
        int ind = i;
        for (int j = i + 1; j < r; j++)
        {
            if (arr[j] < arr[ind])
                ind = j;
        }
        swap(arr[i], arr[ind]);
    }
    return;
}

int main()
{
    int *arr = getRandData(SMALL_DATA_N);
    TEST(selection_sort, arr, SMALL_DATA_N);
    free(arr);
    system("pause");
    return 0;
}