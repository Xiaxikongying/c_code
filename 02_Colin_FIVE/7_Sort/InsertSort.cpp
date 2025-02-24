#include <iostream>
using namespace std;

void InsertSort(int *arr, int n)
{
    if (arr == NULL || n == 1)
        return;

    for (int i = 1; i < n; i++)
    {
        int insert = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > insert)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = insert;
    }
    return;
}

int main()
{
    int arr[] = {9, 7, 6, 4, 2, 8, 3, 45, 1, 101, 1021, 0, 65, 8954, 13, 3};
    int len = sizeof(arr) / sizeof(int);
    InsertSort(arr, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}