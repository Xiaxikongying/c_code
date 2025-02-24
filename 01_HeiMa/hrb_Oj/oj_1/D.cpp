#include <iostream>
#include <cstring>
using namespace std;
int alive[100];
int main()
{

    int n, m;

    while (cin >> n >> m)
    {
        // n个人  数到m的死
        memset(alive, 0, sizeof(alive));
        int a = 0; //数数
        int b = 0; //已死亡人数

        for (int i = 1; b != n - 1; i++)
        {
            if (i == n + 1)
                i = 1;

            if (alive[i] == 0)
            {
                a++;
                if (a == m)
                {
                    alive[i] = -1;
                    b++;
                    a = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (alive[i] == 0)
                cout << i << endl;
        }
    }
    system("pause");
    return 0;
}