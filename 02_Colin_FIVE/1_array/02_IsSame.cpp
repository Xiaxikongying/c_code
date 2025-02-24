#include <iostream>
#include <time.h>
using namespace std;
//判断数组中是否有数值的下标
bool isSame(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == i) //判断值是否与下标相同 ，若相同，则继续
            continue;
        else if (arr[i] == arr[arr[i]]) //判断当前值对应下标是否与自己相同 若相同则return 0 ，若不同则交换两者
            return false;
        swap(arr[i], arr[arr[i]]);
    }
    return true;
}

void isSame1(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] != i)
        {
            if (arr[i] == arr[arr[i]])
            {
                printf("X\n");
                return;
            }
            swap(arr[i], arr[arr[i]]);
        }
        else
            continue;
    }
    printf("√\n");
}

int main()
{
    srand(time(0));
    int n;
    cin >> n;
    int arr[n];
    //输入数据
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
        //cin >> arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    isSame1(arr, n);
    /*
        if (isSame(arr, n))
            cout << "无重复" << endl;
        else
            cout << "有重复" << endl;
            */

    system("pause");
    return 0;
}