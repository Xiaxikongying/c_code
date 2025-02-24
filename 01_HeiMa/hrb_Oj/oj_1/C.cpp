#include <iostream>
using namespace std;

int main()
{
    int arr[1000];
    int n;
    while (cin >> n)
    {
        int number = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int d;
        cin >> d;//需要删除的数

        cout << n << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << arr[n - 1] << endl;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != d)
            {
                arr[number] = arr[i];
                number++;
            }
        }

        cout << number << endl;
        for (int i = 0; i < number - 1; i++)
        {
            cout << arr[i] << " ";
        }
        if (number >= 1)
            cout << arr[number - 1] << endl;
    }

    system("pause");
    return 0;
}