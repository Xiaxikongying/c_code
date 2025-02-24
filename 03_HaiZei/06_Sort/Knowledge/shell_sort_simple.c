#include <stdio.h>
#include <stdlib.h>

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shell_sort(int arr[], int n)
{
    int i, j, key;
    int step;
    for (step = n / 2; step > 0; step /= 2)
    {
        //插入排序
        for (i = step; i < n; i++)
        {
            key = arr[i];
            for (j = i; j >= step && key < arr[j - step]; j -= step)
                arr[j] = arr[j - step]; 
            arr[j] = key;
        }
    }
}

int main()
{
    int arr[] = {10, 9, 7, 50, 47, 69, 99, 11, 55, 687, 26, 45, 16, 58, 43, 64};
    print_arr(arr, 16);
    shell_sort(arr, 16);
    print_arr(arr, 16);
    system("pause");
    return 0;
}