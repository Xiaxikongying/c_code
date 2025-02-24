#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_Test.h"

/*
1、将数组分成『待排序区』和『已排序区』
2、从头到尾扫描『待排序区』，若前面元素比后面元素⼤，则交换
3、每⼀轮都会将『待排序区』中最⼤的放到『已排序区』的开头
4、直到『待排序区』没有元素为⽌
*/

void bubble_sort(int *arr, int l, int r)
{
    for (int i = 0; i < r; i++)
    {
        int cnt = 0; //记录交换的次数
        for (int j = 0; j < r - i; j++)
        {
            if (arr[j] <= arr[j + 1])
                continue;
            swap(arr[j], arr[j + 1]);
            cnt += 1;
        }
        if (cnt == 0) //若交换次数为0，则表示已经完成排序
            break;
    }
    return;
}

int main()
{
    int *arr1 = getRandData(SMALL_DATA_N);
    int *arr2 = getRandData(BIG_DATA_N);
    TEST(bubble_sort, arr1, SMALL_DATA_N);
    TEST(bubble_sort, arr2, BIG_DATA_N);
    free(arr1);
    free(arr2);
    system("pause");
    return 0;
}