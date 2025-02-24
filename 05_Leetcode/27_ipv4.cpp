#include <iostream>
using namespace std;

int main()
{
    char scr[] = "192.168.2.20";
    char des[8] = {0};
    int arr[4] = {0};
    sscanf(scr, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
    sprintf(des, "%2.2x%2.2x%2.2x%2.2x", arr[0], arr[1], arr[2], arr[3]);

    for (int i = 0; i < 8; i++)
    {
        if (des[i] >= 'a' && des[i] <= 'f')
            des[i] -= 32;
    }

    cout << des << endl;

    system("pause");
    return 0;
}
