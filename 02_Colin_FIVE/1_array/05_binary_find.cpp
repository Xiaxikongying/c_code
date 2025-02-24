#include <iostream>
using namespace std;

int binary_find1(int *arr, int head, int tail, int find) //递归
{
    if (head > tail)
        return -1;

    int mid = (head + tail) / 2;
    if (arr[mid] == find)
        return mid;
    if (arr[mid] > find)
        tail = mid - 1;
    if (arr[mid] < find)
        head = mid + 1;

    return binary_find1(arr, head, tail, find);
}

int binary_find2(int *arr, int n, int find) //循环
{
    int head = 0;
    int tail = n - 1;
    int mid;
    while (head <= tail)
    {
        mid = (head + tail) / 2;
        if (arr[mid] == find)
            return mid;
        if (arr[mid] > find)
            tail = mid - 1;
        if (arr[mid] < find)
            head = mid + 1;
    }
    return -1;
}
