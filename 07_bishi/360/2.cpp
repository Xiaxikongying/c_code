#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        vector<int> l(n, 1);
        vector<int> r(n, 1);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        for (int i = 1; i < n; ++i)
        {
            if (arr[i] > arr[i - 1])
                l[i] += l[i - 1];
        }
        for (int i = n - 2; i >= 0; --i)
        {
            if (arr[i] < arr[i + 1])
                r[i] += r[i + 1];
        }

        int res = *max_element(l.begin(), l.end());
        for (int i = 1; i < n - 1; ++i)
        {
            if (arr[i - 1] + 1 < arr[i + 1])
            {
                res = max(res, l[i - 1] + r[i + 1]);
            }
        }
        cout << res + 1 << endl;
    }
    system("pause");
    return 0;
}
/*
3
5
3 6 2 3 1
6
1 1 4 5 1 4
10
7 8 3 5 6 1 2 4 9 10


3
4
6
*/
