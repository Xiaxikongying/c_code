#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

#define Father(n) ((int)(ceil((double)n / 2)) - 1)
#define lchild(n) (n * 2 + 1)
#define rchild(n) (n * 2 + 2)

void heap_sort(int *arr, int len)
{

    //-------heap_build------------------
    
    for (int i = len - 1; i > 0; i--)
    {
        if (arr[i] > arr[Father(i)]) //孩子比父亲大
            swap(arr[i], arr[Father(i)]);
    }

    int ind = 0;
    while (lchild(ind) < len)
    {
        //右孩子存在 且比左孩子大  也比ind大
        if (rchild(ind) < len - 1 && arr[lchild(ind)] < arr[rchild(ind)] && arr[rchild(ind)] > arr[ind])
            swap(arr[ind], arr[rchild(ind)]);

        //左孩子比ind 大
        else if (arr[lchild(ind)] > arr[ind])
            swap(arr[ind], arr[lchild(ind)]);

        // ind 大于 左右孩子
        ind++;
    }

    //-----------sort------------------
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        int ind = 0;
        while (lchild(ind) < i)
        {
            //右孩子存在 且比左孩子大  也比ind大
            if (rchild(ind) < i && arr[lchild(ind)] < arr[rchild(ind)] && arr[rchild(ind)] > arr[ind])
            {
                swap(arr[ind], arr[rchild(ind)]);
                ind = rchild(ind);
            }

            //左孩子比ind 大
            else if (arr[lchild(ind)] > arr[ind])
            {
                swap(arr[ind], arr[lchild(ind)]);
                ind = lchild(ind);
            }
            // ind 大于 左右孩子
            else
                break;
        }
    }
}

int main()
{

    //int arr1[] = {9, 7, 6, 4, 2, 8, 3, 45, 1, 101, 1021, 0, 65, 8954, 13, 3};
    int arr[10];
    srand(time(0));
    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 10000 +1;

    int len = sizeof(arr) / sizeof(int);
    heap_sort(arr, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}