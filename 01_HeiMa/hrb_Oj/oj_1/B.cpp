#include <iostream>
using namespace std;

int main()
{
    int arr[1005];
    int n;
    while (cin >> n)
    {
        int number = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            flag = true;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] == arr[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
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
        cout << arr[number - 1] << endl;
    }

    system("pause");
    return 0;
}