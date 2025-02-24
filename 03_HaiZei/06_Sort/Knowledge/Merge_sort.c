#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_Test.h"

int *buff;
void merge_sort(int *arr, int l, int r)
{
    if (r - l <= 1)
        return;
    //分治
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    //将序列分成若干个小序列   

    //合并
    int p1 = l, p2 = mid, k = 0;
    while (p1 < mid || p2 < r)
    {
        // p1比p2小 或者p2内的数据已经用光
        if ((p1 < mid && arr[p1] <= arr[p2]) || p2 == r)
            buff[k++] = arr[p1++];
        else
            buff[k++] = arr[p2++];
    }

    for (int i = l; i < r; i++)
    {
        //右边数组归并到大数组中时， l的值不为0，但是buff数组是从0开始记录数字的
        //所以要减去l
        arr[i] = buff[i - l];
    }

    return;
}

int main()
{
    buff = (int *)malloc(sizeof(int) * (BIG_DATA_N));
    int *arr1 = getRandData(SMALL_DATA_N);
    int *arr2 = getRandData(BIG_DATA_N);
    TEST(merge_sort, arr1, SMALL_DATA_N);
    TEST(merge_sort, arr2, BIG_DATA_N);
    free(arr1);
    free(arr2);
    free(buff);

    system("pause");
    return 0;
}