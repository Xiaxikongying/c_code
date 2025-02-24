#include <iostream>
using namespace std;

void SelectSort(int *arr, int n)
{
    if (arr == NULL || n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        int ind = 0;
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j] > arr[ind])
                ind = j;
        }
        if (ind != n - i - 1)
            swap(arr[ind], arr[n - i - 1]);
    }
    return;
}

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int arr[] = {9, 7, 6, 4, 2, 8, 3, 45, 1, 101, 1021, 0, 65, 8954, 13, 3};
    int len = sizeof(arr) / sizeof(int);
    SelectSort(arr, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}