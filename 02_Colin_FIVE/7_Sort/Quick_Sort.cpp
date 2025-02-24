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

    int x = l;      //左指针 指向数组的开头
    int y = r - 1;  //右指针  指向数组的尾部
    int z = arr[x]; //基准值

    while (x < y)
    {
        while (x < y && arr[y] >= z) //在尾部寻找一个小于Z的值
            y--;
        if (x < y && arr[y] < z)
        {
            arr[x] = arr[y];
            x++;
        }

        while (x < y && arr[x] <= z) //在头部寻找一个大于Z的值
            x++;
        if (x < y && arr[x] > z)
        {
            arr[y] = arr[x];
            y--; 
        }
    }
    arr[x] = z; // x = y时 执行该句

    Quick_Sort(arr, l, x); //递归 左闭右开
    Quick_Sort(arr, x + 1, r);

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

    Quick_Sort(arr, 0, len);

    end = clock();
    printf("%lldms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);
    system("pause");
    return 0;
}