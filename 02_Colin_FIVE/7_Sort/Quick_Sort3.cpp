#include <iostream>
#include <ctime>
using namespace std;

void Quick_Sort(int *arr, int l, int r)
{
    //结束条件
    if (r - l <= 2)
    {
        if (r - l <= 1) // 0 或 1 个元素
            return;
        if (arr[l] > arr[l + 1]) // 2个元素
            swap(arr[l], arr[l + 1]);
        return;
    }

    int x = l - 1;
    int y = l;
    int z = arr[r - 1]; //基准值
    while (y < r - 1)
    {
        if (arr[y] < z)
            swap(arr[y], arr[++x]);
        y++;
    }
    if (++x != r - 1)
        swap(arr[r - 1], arr[x]);

    Quick_Sort(arr, l, x); //递归 左闭右开
    Quick_Sort(arr, x + 1, r);

    return;
}

void Quick_Sort222(int *arr, int l, int r)
{
    //结束条件
    if (r - l <= 2)
    {
        if (r - l <= 1) // 0 或 1 个元素
            return;
        if (arr[l] > arr[l + 1]) // 2个元素
            swap(arr[l], arr[l + 1]);
        return;
    }

    int x = l - 1;
    int y = l;
    for (y; y < r - 1; y++)
    {
        if (arr[y] < arr[r - 1])
        {
            if (++x != y)
                swap(arr[x], arr[y]);
        }
    }
    if (++x != r - 1)
        swap(arr[x], arr[r - 1]);

    Quick_Sort222(arr, l, x); //递归 左闭右开
    Quick_Sort222(arr, x + 1, r);

    return;
}
int main()
{
    time_t begin, end;
    begin = clock();
    srand(time(0));

    int arr[500000];
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < 500000; i++)
        arr[i] = rand() % 500000 + 1;

    Quick_Sort222 (arr, 0, len);

    end = clock();
    printf("%lldms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);
    system("pause");
    return 0;
}