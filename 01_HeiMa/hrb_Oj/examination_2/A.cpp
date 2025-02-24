#include <iostream>
using namespace std;
//折半查找

void half(int arr[], int max, int min, int a)
{
    int h = (max + min) / 2; 
    if (max <= min && arr[h] != a)
    {
        cout << "No" << endl;
        return;
    }

    if (arr[h] > a)
    {
        max = h - 1;
    }
    else if (arr[h] < a)
    {
        min = h + 1;
    }
    if (arr[h] == a)
    {
        cout << "Yes" << endl;
        return;
    }

    half(arr, max, min, a);
}

int main()
{
    int n;
    int arr[10005];

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int a;
        cin >> a;
        int min = 0;
        int max = n;
        half(arr, max, min, a);
    }
    system("pause");
    return 0;
}
