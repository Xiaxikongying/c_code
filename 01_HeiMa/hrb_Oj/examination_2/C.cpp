#include <iostream>
#include <cstring>
using namespace std;
//图入度出度

int main()
{
    int m, n;
    int ru[505];
    int chu[505];
    while (cin >> m >> n)
    {
        memset(ru, 0, sizeof(ru));
        memset(chu, 0, sizeof(chu));

        int a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            ru[a-1]++;
            chu[b-1]++;
        }

        for (int i = 0; i < m - 1; i++)
        {
            cout << chu[i] << " ";
        }
        cout << chu[m - 1] << endl;
        for (int i = 0; i < m - 1; i++)
        {
            cout << ru[i] << " ";
        }
        cout << ru[m - 1] << endl;
    }
    // system("pause");
    return 0;
}
