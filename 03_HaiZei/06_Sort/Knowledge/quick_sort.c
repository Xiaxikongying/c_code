#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "sort_Test.h"

void quick_sort(int *arr, int l, int r)
{
    if (r - l <= 2)
    {
        if (r - l <= 1)
            return;
        if (arr[l] > arr[l + 1])
            swap(arr[l], arr[l + 1]);
    }
    // partition
    int x = l , y = r - 1;
    int z = arr[l]; //基准值
    while (x < y)
    {
        while (x < y && z <= arr[y])
            --y; //尾部指针 向前移动找到一个小于基准值的数
        if (x < y)
        {
            arr[x] = arr[y];
            x++;
        }
        while (x < y && z >= arr[x])
            ++x; //头部指针 向前移动找到一个大于基准值的数
        if (x < y)
        {
            arr[y] = arr[x];
            y--;
        }
    }
    arr[x] = z; //跳出循环 头尾重合
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);
    return;
}

void v1_quick_sort(int *arr, int l, int r)
{
    //处理边界条件
    if (r - l <= 2)
    {
        if (r - l <= 1)
            return;
        if (arr[l] > arr[l + 1])
            swap(arr[l], arr[l + 1]);
    }

    // partition
    int x = l, y = r - 1;
    int z = arr[l]; //基准值
    do
    {
        while (arr[x] < z)
            ++x; //找到一个大于等于z的arr[x]
        while (arr[y] > z)
            --y; //找到一个小于等于z的arr[y]
        if (x <= y)
        {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);

    v1_quick_sort(arr, l, x);
    v1_quick_sort(arr, x, r);
    return;
}

//三点取中法
int three_point_select(int a, int b, int c)
{
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
    return b;
    //返回中值
}
void v2_quick_sort(int *arr, int l, int r)
{
    if (r - l <= 2)
    {
        if (r - l <= 1)
            return;
        if (arr[l] > arr[l + 1])
            swap(arr[l], arr[l + 1]);
        return;
    }
    // partition
    int x = l, y = r - 1;
    int z = three_point_select(
        arr[l],
        arr[r - 1],
        arr[(l + r) / 2]);
    do
    {
        while (arr[x] < z)
            ++x;
        while (arr[y] > z)
            --y;
        if (x <= y)
        {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);
    v2_quick_sort(arr, l, x);
    v2_quick_sort(arr, x, r);
    return;
}

//优化递归次数
void v3_quick_sort(int *arr, int l, int r)
{
    //处理边界条件
    if (r - l <= 2)
    {
        if (r - l <= 1)
            return;
        if (arr[l] > arr[l + 1])
            swap(arr[l], arr[l + 1]);
    }

    while (l < r) //用一个循环代替递归
    {
        // partition
        int x = l, y = r - 1;
        int z = arr[l]; //基准值
        do
        {
            while (arr[x] < z)
                ++x; //找到一个大于等于z的arr[x]
            while (arr[y] > z)
                --y; //找到一个小于等于z的arr[y]
            if (x <= y)
            {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);

        v3_quick_sort(arr, l, x);
        l = x;
    }
    return;
}

void v4_quick_sort(int *arr, int l, int r);
#define threshold 16

    void unguarded_insert_sort(int *arr, int l, int r)
{
    int ind = l;
    for (int i = l + 1; i < r; i++)
    {
        if (arr[i] < arr[ind])
            ind = i;
    }
    while (ind > l)
    {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    }
    for (int i = l + 1; i < r; i++)
    {
        int j = i;
        while (arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
    return;
}

void __v4_quick_sort(int *arr, int l, int r)
{
    while (r - l > threshold)
    {
        // partition
        int x = l, y = r - 1;
        int z = three_point_select(
            arr[l],
            arr[r - 1],
            arr[(l + r) / 2]);
        do
        {
            while (arr[x] < z)
                ++x;
            while (arr[y] > z)
                --y;
            if (x <= y)
            {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        v4_quick_sort(arr, l, x); // left
        l = x;
    }
    return;
}

void v4_quick_sort(int *arr, int l, int r)
{
    __v4_quick_sort(arr, l, r);
    unguarded_insert_sort(arr, l, r);
    return;
}

int main()
{
    int *arr1 = getRandData(SMALL_DATA_N);
    int *arr2 = getRandData(BIG_DATA_N);
    TEST(quick_sort, arr1, SMALL_DATA_N);
    TEST(quick_sort, arr2, BIG_DATA_N);
    TEST(v1_quick_sort, arr2, BIG_DATA_N);
    TEST(v2_quick_sort, arr2, BIG_DATA_N);
    TEST(v3_quick_sort, arr2, BIG_DATA_N);
    TEST(v4_quick_sort, arr2, BIG_DATA_N);
    ;
    free(arr1);
    free(arr2);
    system("pause");
    return 0;
}