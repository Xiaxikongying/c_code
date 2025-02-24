#include <iostream>
#include <cstring>
using namespace std;

/*
数据重复 且有范围 3-9
*/
int getMin(int *arr, int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int getMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}
void CountingSort(int *arr, int n)
{
    if (arr == NULL || n == 1)
        return;
    //首先要找到该数据的最大最小值 来开辟cont数组
    int min = getMin(arr, n);
    int max = getMax(arr, n);
    int m = max - min + 1;
    int *count = (int *)malloc(sizeof(int) * m);
    memset(count, 0, sizeof(int) * m);
    for (int i = 0; i <= n - 1; i++)
        count[arr[i] - min]++;
    //前项和序列
    for (int i = 1; i < m; i++)
        count[i] += count[i - 1];

    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; i--)
    {
        temp[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    //将temp数组复杂到arr中
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    free(count);
    count = NULL;
    free(temp);
    temp = NULL;
    return;
}

int main()
{
    int arr[] = {9, 7, 6, 4, 6, 7, 9, 8, 7, 6, 8, 3, 4, 3}; // 3-9
    int len = sizeof(arr) / sizeof(int);
    CountingSort(arr, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}