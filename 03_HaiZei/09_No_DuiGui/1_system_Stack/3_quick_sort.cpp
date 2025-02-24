#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <time.h>
#include <algorithm>
#include "sort_Test.h"
using namespace std;

#define swap(a, b)           \
    {                        \
        __typeof(a) __c = a; \
        a = b, b = __c;      \
    }

void quick_sort(int *arr, int l, int r)
{
    // code 0
    if (r - l <= 2)
    {
        if (r - l <= 1)
            return;
        if (arr[l] > arr[l + 1])
            swap(arr[l], arr[l + 1]);
    }

    // code 1
    //  partition
    int x = l, y = r - 1;
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

    // code 2
    quick_sort(arr, l, x);
    // code 3
    quick_sort(arr, x + 1, r);
    // code 4
    return;
}

struct Data
{
    Data(int *arr, int l, int r) : arr(arr), r(r), l(l), code(0) {}
    int *arr, l, r;
    int x;
    int code;
};

void non_quick_sort(int *arr, int l, int r)
{
    stack<Data> s;
    Data d(arr, l, r);
    s.push(d);
    while (!s.empty())
    {
        Data &cur = s.top();
        switch (cur.code)
        {

        case 0:
        {
            if (cur.r - cur.l <= 2)
            {
                if (cur.r - cur.l <= 1)
                    s.pop();
                else
                {
                    if (cur.arr[cur.l] > cur.arr[cur.l + 1])
                        swap(cur.arr[cur.l], cur.arr[cur.l + 1]);
                    s.pop(); //或者 cur.code = 4;
                }
            }
            else
            {
                cur.code = 1;
            }
        }
        break;

        case 1:
        {
            int x = cur.l, y = cur.r - 1;
            int z = cur.arr[cur.l]; //基准值
            while (x < y)
            {
                while (x < y && z <= cur.arr[y])
                    --y; //尾部指针 向前移动找到一个小于基准值的数
                if (x < y)
                {
                    cur.arr[x] = cur.arr[y];
                    x++;
                }

                while (x < y && z >= cur.arr[x])
                    ++x; //头部指针 向前移动找到一个大于基准值的数
                if (x < y)
                {
                    cur.arr[y] = cur.arr[x];
                    y--;
                }
            }
            cur.arr[x] = z; //跳出循环 头尾重合
            cur.x = x;
            cur.code = 2;
        }
        break;

        case 2:
        {
            Data d(cur.arr, cur.l, cur.x);
            cur.code = 3;
            s.push(d);
        }
        break;

        case 3:
        {
            Data d(cur.arr, cur.x + 1, cur.r);
            cur.code = 4;
            s.push(d);
        }
        break;

        case 4:
            s.pop();
            break;
        }
    }
    return;
}

int main()
{
    int *arr1 = getRandData(SMALL_DATA_N);
    int *arr2 = getRandData(BIG_DATA_N);
    TEST(quick_sort, arr1, SMALL_DATA_N);
    TEST(quick_sort, arr2, BIG_DATA_N);
    TEST(non_quick_sort, arr1, SMALL_DATA_N);
    TEST(non_quick_sort, arr2, BIG_DATA_N);

    free(arr1);
    free(arr2);
    system("pause");
    return 0;
}