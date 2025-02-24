#include <iostream>
#include <vector>
#include <time.h>
#include "sort_Test.h"
using namespace std;

int *buff;
void merge_sort(int *arr, int l, int r)
{
    if (r - l <= 1)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);

    int p1 = l, p2 = mid, k = 0;

    while (p1 < mid || p2 < r)
    {
        if ((p1 < mid && arr[p1] <= arr[p2]) || p2 == r)
            buff[k++] = arr[p1++];
        else
            buff[k++] = arr[p2++];
    }
    for (int i = l; i < r; i++)
    {
        arr[i] = buff[i - l];
    }

    return;
}

struct Data
{
    Data(int l, int r) : l(l), r(r) {}
    int l, r;
};
void merge_sort_once(int *arr, int l, int r)
{
    int mid = (l + r) / 2;
    int p1 = l, p2 = mid, k = l;

    while (p1 < mid || p2 < r)
    {
        if ((p1 < mid && arr[p1] <= arr[p2]) || p2 == r)
            buff[k++] = arr[p1++];
        else
            buff[k++] = arr[p2++];
    }

    for (int i = l; i < r; i++)
        arr[i] = buff[i];
    return;
}

void non_merge_sort(int *arr, int l, int r)
{
    Data init_d(l, r);
    vector<Data> d_arr;
    d_arr.push_back(init_d);

    for (int i = 0; i < d_arr.size(); i++)
    {

        int ll = d_arr[i].l;
        int rr = d_arr[i].r;
        int mid = (ll + rr) / 2;

        if (mid - ll >= 2)
            d_arr.push_back(Data(ll, mid));
        if (rr - mid >= 2)
            d_arr.push_back(Data(mid, rr));
    }

    for (int i = d_arr.size() - 1; i >= 0; i--)
        merge_sort_once(arr, d_arr[i].l, d_arr[i].r);
    return;
}

int main()
{
    buff = (int *)malloc(sizeof(int) * (BIG_DATA_N));
    int *arr1 = getRandData(SMALL_DATA_N);
    int *arr2 = getRandData(BIG_DATA_N);
    // TEST(merge_sort, arr1, SMALL_DATA_N);
    // TEST(merge_sort, arr2, BIG_DATA_N);
    TEST(non_merge_sort, arr1, SMALL_DATA_N);
    TEST(non_merge_sort, arr2, BIG_DATA_N);
    free(arr1);
    free(arr2);
    free(buff);

    system("pause");
    return 0;
}