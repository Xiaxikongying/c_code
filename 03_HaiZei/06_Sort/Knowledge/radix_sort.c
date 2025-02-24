#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_Test.h"

#define k 65536

void radix_sort(int *arr, int l, int r)
{

    int *cnt = (int *)malloc(sizeof(int) * k); //每种数字出现次数
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    
    //"个位"排序
    memset(cnt, 0, sizeof(int) * k);
    for (int i = l; i < r; i++)
        cnt[arr[i] % k]++; //计算每个数 有多少个

    for (int i = 1; i < k; i++)
        cnt[i] += cnt[i - 1]; //统计每个个位数 应在数组的哪个位子

    for (int i = r - 1; i >= l; i--)
        temp[--cnt[arr[i] % k]] = arr[i];
    memcpy(arr + l, temp, sizeof(int) * (r - l));

    //"十位"排序
    memset(cnt, 0, sizeof(int) * k);
    for (int i = l; i < r; i++)
        cnt[arr[i] / k]++; //计算每个数 有多少个

    for (int i = 1; i < k; i++)
        cnt[i] += cnt[i - 1]; //统计每个个位数 应在数组的哪个位子

    for (int i = r - 1; i >= l; i--)
        temp[--cnt[arr[i] / k]] = arr[i];
    memcpy(arr + l, temp, sizeof(int) * (r - l));

    return;
}

int main()
{

    int *arr1 = getRandData(SMALL_DATA_N);
    int *arr2 = getRandData(BIG_DATA_N);
    TEST(radix_sort, arr1, SMALL_DATA_N);
    TEST(radix_sort, arr2, BIG_DATA_N);
    free(arr1);
    free(arr2);

    system("pause");
    return 0;
}