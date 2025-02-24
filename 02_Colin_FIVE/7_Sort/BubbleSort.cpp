#include <iostream>
using namespace std;

void BubbleSort(int *arr, int n)
{
    if (arr == NULL || n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                cnt = n - (j + 1); //记录最后一次交换的位置，然后减去，就是已排好序元素的个数
            }
        }
        if (cnt == 0)
            return;
        else
            i = cnt - 1; //-1是因为下一次循环会i++
    }
    return;
}

int main()
{

    int arr[] = {9, 7, 6, 4, 2, 8, 3, 45, 1, 101, 1021, 0, 65, 8954, 13, 3};
    int len = sizeof(arr) / sizeof(int);
    BubbleSort(arr, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}