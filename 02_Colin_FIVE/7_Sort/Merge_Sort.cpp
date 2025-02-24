#include <iostream>
using namespace std;
int *buff;
void Merge_Sort(int *arr, int l, int r)
{
    if (r - l <= 1)
        return;

    int mid = (r + l) / 2;
    Merge_Sort(arr, l, mid);
    Merge_Sort(arr, mid, r);

    int a = l, b = mid;
    int k = 0;
    while (a < mid || b < r)
    {
        if (b >= r || (a < mid && arr[a] < arr[b])) //将a部分存入----> b已经存完 或  a部分的值比b部分小
            buff[k++] = arr[a++];
        else
            buff[k++] = arr[b++]; //将b部分存入----->a部分不存时
    }

    for (int i = l; i < r; i++)
        arr[i] = buff[i - l];
    return;
}

int main()
{
    int arr[] = {9, 7, 6, 4, 2, 8, 3, 45, 1, 101, 1021, 0, 65, 8954, 13, 3};
    int len = sizeof(arr) / sizeof(int);
    buff = (int *)malloc(sizeof(int) * len);
    Merge_Sort(arr, 0, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    free(buff);
    system("pause");
    return 0;
}