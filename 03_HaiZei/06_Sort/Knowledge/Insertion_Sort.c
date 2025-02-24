#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_Test.h"
/*
1、将数组分成『已排序区』和『待排序区』
2、将『已排序区』后面⼀个元素，向前插⼊到『待排序区』中
3、直到『待排序区』没有元素为⽌
*/

void insert_sort(int *arr, int l, int r)
{
    for (int i = l + 1; i < r; i++)
    {
        int j = i;
        while (arr[j] < arr[j - 1] && j > l)
        {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
}

void unguarded_insert_sort(int *arr, int l, int r)
{
    int ind = l;
    for (int i = l + 1; i < r; i++)
    {
        if (arr[i] < arr[ind])
            ind = i;
    }
    // swap(arr[ind], arr[l]);  会使得插入排序变得不稳定
    while (ind > l)
    {
        swap(arr[ind], arr[ind - 1]);
        ind--;
    }
    //先把序列中最小值提到最前边

    for (int i = l + 1; i < r; i++)
    {
        int j = i;
        while (arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
}

int main()
{
    int *arr1 = getRandData(SMALL_DATA_N);
    int *arr2 = getRandData(SMALL_DATA_N);
    TEST(insert_sort, arr1, SMALL_DATA_N);
    TEST(unguarded_insert_sort, arr2, SMALL_DATA_N);
    free(arr1);
    free(arr2);
    system("pause");
    return 0;
}