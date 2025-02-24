#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int r[41];
    int i = 0, k = 0;
    int m ;  //数到几
    int n;   //当前活着的人数
    cin >> n >> m;
    for (i = 0; i < 41; i++)
        r[i] = i + 1;

    for (; n > 1; n--)
    {
        i = (i + m - 1) % n;
        
        for (k = i + 1; k < n; k++)
        {
            r[k - 1] = r[k];
        }
    }
    printf("%d\n", r[0]);
    system("pause");
    return 0;
}